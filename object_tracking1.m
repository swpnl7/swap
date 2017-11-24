clc;
close all;
clear all;

% video_object= VideoReader('singleball.avi');
video_object= VideoReader('walk1_mpeg2video_005.avi');
nframes= video_object.Numberofframes;
len= video_object.Height;
wid= video_object.Width;
sum = zeros(len, wid);
box=[0 0 0 0];
for k= 1: nframes
    frame= read(video_object,k);
    frame = rgb2gray(frame);
    temp = double(frame);
    sum = sum + temp;
    back = uint8(sum ./ k);
    object= false(len,wid);
    object((frame - back)> 50) = 1;
    blobanalyser= vision.BlobAnalysis;
    [area,centroid,bbox]= step(blobanalyser, object);
    box=bbox;
    label = 'object';
    
    
    subplot(2,2,1); 
    frame = insertObjectAnnotation(frame,'rectangle', bbox , label);
    imshow(frame);
    pause(0.05);
    subplot(2,2,2); imshow(back);
    subplot(2,2,3); imshow(object);
    
end

    
    
    