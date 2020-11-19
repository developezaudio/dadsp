%Calculates average snr dbc of specified files in directory
%In its current state filename must be same initially followed by 
%int starting from 1 and numberof files must be specified
i = 1;
filedir = "/Users/johnnylopez/Downloads/Christian2.2.1QA/";
commonfilename = "test";
filename =  filedir + commonfilename + i + ".wav";
[x, Fs] = audioread(filename);
y1  = snr(x);
disp(y1);
numfiles=6;
accum = 0;

for c = 1:numfiles
    filename =  filedir + commonfilename + c + ".wav";
    [x, Fs] = audioread(filename);
    y1  = snr(x);
    disp(y1);
    accum = accum + y1;
end
disp("accum = " + accum);
average =  accum/s;
disp("average = " + average);
