class Solution {
public:
    vector<int> partitionLabels(string s) {
      //array to track the last occurrence of each letter
        vector<int> v(26,-1);
        int n = s.size();
        for(int i =0; i< n; i++){
            v[s[i]-'a'] = i;
        }
      //result array
        vector<int> res;
        int d = 0;
        int st = 0, e = 0, p = 0;
      
        while(p<n){
          //find the maximum end of our current substring
            e = max(e, v[s[p] - 'a']);
          //calculate the length of the substring
            d = max(d, e-st);

            if(p == e){
              //add the length to the array if we reach the end of the substring (pos == end)
                res.push_back(d+1);
                st = p+1;
                d = 0;
            }
            p++;
        }
        return res;
    }
};
