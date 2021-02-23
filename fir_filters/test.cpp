#include <iostream>
#include <cstdio>
#include <sndfile.hh>
#include "Biquad.h"    
    
int main(int argc, const char *argv[]) {
    float gain;
    clock_t starttime,endtime;

    const int bframes = 1024;
    SNDFILE *fin, *fout;
    SF_INFO info_in, info_out;
    double* inbuf;
    inbuf = new double[bframes * 1];
    double* outbuf;    

    if((fin = sf_open(argv[1], SFM_READ, &info_in)) != NULL) {

         if(info_in.channels == 1){
            info_out.format = info_in.format;
            info_out.samplerate = info_in.samplerate;
            info_out.channels = 1;
            if((fout = sf_open(argv[2],
                    SFM_WRITE, &info_out)) != NULL){
                        int cnt;    
                        starttime = clock();
                        do {
                            //printf("Loading buffer Num %d \n ... \n", bufferNum);
                            cnt = sf_read_double(fin, inbuf, bframes);
                            
                            sf_write_double(fout,outbuf,cnt);
                        } while (cnt > 0);
                        endtime = clock();
                        printf("Finished running postAudioProcessing main loop.... \n .......\n");
	                    printf("Total time elapsed = %f secs\n", (endtime - starttime)/(double)CLOCKS_PER_SEC);
                            printf("Closing input file\n ....");
                            sf_close(fin);
                            printf("Input file closed \n");
                            printf("Closing output file\n ....");
                            sf_close(fout);
                            printf("output file closed \n");
                }
                else {
                        sf_close(fin);
                        printf("ERROR: could not open %s \n", argv[2]);
                        return 1;
                }
            }
            else {
                sf_close(fin);
                printf("ERROR: input %s not mono\n", argv[1]);
                return 1;
            }
        } else{
            printf("ERROR: could not open %s \n", argv[1]);
            return 1;
        }

    delete[] inbuf;
    delete[] outbuf;
    
    return 0;
}
 