class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        //size of the input vector
        int n = questions.size();

        //edge cases
        if(n==1) return questions[0][0];
        else if(n==2) {
            return questions[0][0] * ( questions[0][0] > questions[1][0]) + 
                questions[1][0] * (questions[0][0] <= questions[1][0]);
        }

        //storing the max values for memorization
        vector<long long> mxa;
        long long mx = questions[n-1][0];
        mxa.push_back(mx);

        
        int i = n-2;
        // loop from the end of the array to find the max points to collect
        while(i>-1){
            long long tp = 0;
            //if the brainpower exceeds the number of elements stored, max points is the points of the ith question
            if(questions[i][1] >= mxa.size()){
                tp = questions[i][0];
            }
            //else the max points collected is the max points to be collected from the "i+brainpower(i)"th question + points(i)
            else{
                tp = (long long) mxa[mxa.size() - questions[i][1]-1] + questions[i][0] ;
            }
            mx = max(mx,tp);
            mxa.push_back(mx);
            i--;
        }
        //return the max value
        return mx;
    }
};
