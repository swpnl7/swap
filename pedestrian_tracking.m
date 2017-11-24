clc;
close all;
clear all;

video_object= VideoReader('atrium.avi');
nframes= video_object.Numberofframes;
len= video_object.Height;
wid= video_object.Width;
objectBright=false(len,wid);
objectDark=false(len,wid);
object=false(len,wid);
for k= 1: nframes-2
    f12=false(len,wid);
    f13=false(len,wid);
    f21=false(len,wid);
    f31=false(len,wid);
    
    f1= read(video_object,k);
    f2=read(video_object,k+1);
    f3=read(video_object,k+2);
    
    g1 = rgb2gray(f1);
    g2 = rgb2gray(f2);
    g3 = rgb2gray(f3);
    
    g=fspecial('gaussian',[5 5],1.4);                                           % 1.4 is the standard deviation 
    g1=filter2(g,g1);
    g2=filter2(g,g2);
    g3=filter2(g,g3);
    
    f12((g1-g2)>10)=true;
    f13((g1-g3)>10)=true;
    f21((g2-g1)>10)=true;
    f31((g3-g1)>10)=true;
    
    se1 = strel('disk',3);
    se2 = strel('disk',14);
    f12= imopen(f12,se1);
    f12= imclose(f12,se2);
    f12= imfill(f12,'holes');
    f13= imopen(f13,se1);
    f13= imclose(f13,se2);
    f13= imfill(f13,'holes');
    f21= imopen(f21,se1);
    f21= imclose(f21,se2);
    f21= imfill(f21,'holes');
    f31= imopen(f31,se1);
    f31= imclose(f31,se2);
    f31= imfill(f31,'holes');
    
    objectBright = f12;
    objectBright(f12 ~= f13) = false;
    objectDark = f21;
    objectDark(f21 ~= f31) = false;
    object = objectBright | objectDark;
    
    blobanalyser= vision.BlobAnalysis;
    blobanalyser.MinimumBlobArea = 400;
    [area,centroid,bbox]= step(blobanalyser, object);
    box=bbox;
    
    label= 'object';
    f1 = insertObjectAnnotation(f1,'rectangle', bbox , label);
        
    subplot(2,1,1); imshow(f1);
    pause(0.01);
    subplot(2,1,2); imshow(object);
    
end

    
    
    