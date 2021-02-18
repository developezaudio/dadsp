%Calculates average snr dbc of specified files in directory
%In its current state filename must be same initially followed by 
%int starting from 1 and numberof files must be specified
i = 1;
filedir = "/Users/johnnylopez/Downloads/aria5.2.0-qa/forsnr/";
commonfilename = "test";
filename =  filedir + commonfilename + i + ".wav";
[x, Fs] = audioread(filename);
y1  = snr(x);
disp(y1);
numfiles=9;
accum = 0;

for c = 0:numfiles
    filename =  filedir + commonfilename + c + ".wav";
    [x, Fs] = audioread(filename);
    y1  = snr(x);
    disp(y1);
    accum = accum + y1;
end
disp("accum = " + accum);
average =  accum/numfiles;
disp("average = " + average);
