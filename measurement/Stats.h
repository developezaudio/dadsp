class StatsBase {
    public:
        StatsBase(){
        };
        ~StatsBase(){
        }
        virtual double mean(double* inarray, int arraysize);
        virtual double std_deviation(double* inarray, int arraysize, double mean);
    private:
};

////Basic Stats functions class
class StatsBasic : StatsBase{
    public:
        StatsBasic(int size) :
            msize{size}
        {
            marray = new double[size];
        };
        ~StatsBasic();
        double mean(double* inarray, int arraysize) override
        {
            collectAdd = 0.0;
            for(int i=0; i < arraysize; i++)
            {
                collectAdd+=inarray[i];
            }
            return collectAdd/arraysize;
        }
        double std_deviation(double* inarray, int arraysize, double mean) override
        {
            collectAdd = 0.0;
            for(int i=0; i < arraysize; i++)
            {
                collectAdd += inarray[i] * inarray[i];
            }
            return collectAdd/arraysize;
        }

    private:
        double* marray;
        int msize;
        double collectAdd{0.0}, mean{0.0};

};
