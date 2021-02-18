% [x, Fs] = audioread('melodic.wav');
% y = bandpass(x,[1200, 3250], Fs);
% %loudness = integratedLoudness(x,Fs);
% rmsloudness = rms(y);
% %[momentary,shortTerm,integrated,range,peak] = loudMtr(y);
% disp(rmsloudness);

i = 1;
filedir = "/Users/johnnylopez/Downloads/jamesf5.2.1-qa/forsnr/";
testfilename = "test";
originalfilename = "orig";
testfile =  filedir + testfilename + i + ".wav";
origfile =  filedir + originalfilename + i + ".wav";
[x, Fs] = audioread(testfile);
rmstest  = rms(x);
disp(rmstest);
numfiles=8;
accumb1 = 0;
accumb2 = 0;
accumb3 = 0;
accumb4 = 0;

for c = 1:numfiles
    %testfile =  filedir + testfilename + c + ".wav";
    [x, Fs] = audioread(filedir + testfilename + c + ".wav");
    y1b1 = bandpass(x,[50, 300], Fs);
    y1b2 = bandpass(x,[300, 1000], Fs);
    y1b3 = bandpass(x,[1000, 3250], Fs);
    y1b4 = bandpass(x,[8000, 20000], Fs);
    rmstestb1 = rms(y1b1);
    rmstestb2 = rms(y1b2);
    rmstestb3 = rms(y1b3);
    rmstestb4 = rms(y1b4);
    [x2, Fs2] = audioread(filedir + originalfilename + c + ".wav");
    y2b1 = bandpass(x2,[50, 300], Fs);
    y2b2 = bandpass(x2,[300, 1000], Fs);
    y2b3 = bandpass(x2,[1000, 3250], Fs);
    y2b4 = bandpass(x2,[8000, 20000], Fs);
    rmsorigb1 = rms(y2b1);
    rmsorigb2 = rms(y2b2);
    rmsorigb3 = rms(y2b3);
    rmsorigb4 = rms(y2b4);
    disp(rmsorigb1/rmstestb1);
    accumb1 = accumb1 + rmsorigb1/rmstestb1;
    accumb2 = accumb2 + rmsorigb2/rmstestb2;
    accumb3 = accumb3 + rmsorigb3/rmstestb3;
    accumb4 = accumb4 + rmsorigb4/rmstestb4;
end
averageb1 = accumb1/numfiles;
averageb2 = accumb2/numfiles;
averageb3 = accumb3/numfiles;
averageb4 = accumb4/numfiles;
disp("accum b1 = " + accumb1);
disp("average b1 = " + averageb1);
disp("average dbfs b1 = " + 20.0*log10(1.0/averageb1));
disp("accum b2 = " + accumb2);
disp("average b2 = " + averageb2);
disp("average dbfs b2 = " + 20.0*log10(1.0/averageb2));
disp("average b3 = " + averageb3);
disp("average dbfs b3 = " + 20.0*log10(1.0/averageb3));
disp("average b4 = " + averageb4);
disp("average dbfs b4 = " + 20.0*log10(1.0/averageb4));