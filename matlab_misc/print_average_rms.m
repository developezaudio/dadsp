i = 1;
filedir = "/Users/johnnylopez/Downloads/jamesf-qa/forsnr/";
commonfilename = "test";
filename =  filedir + commonfilename + i + ".wav";
[x, Fs] = audioread(filename);
y1  = peak2rms(x);
disp(y1);
numfiles=8;
accum = 0;

for c = 1:numfiles
    filename =  filedir + commonfilename + c + ".wav";
    [x, Fs] = audioread(filename);
    y1  = peak2rms(x);
    disp(y1);
    accum = accum + y1;
end
disp("accum crest = " + accum);
average =  accum/numfiles;
disp("average crest= " + average);
disp("average crest= " + average);
disp("average crest db= " + 20*log10(1.0/average));