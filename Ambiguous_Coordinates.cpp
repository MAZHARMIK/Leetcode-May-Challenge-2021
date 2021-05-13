class Solution {
public:
    string getPair(const string& a, const string& b) {
        return "(" + a + ", " + b + ")";
    }
    
    vector<string> ambiguousCoordinates(string s) {
        s = s.substr(1, s.length()-2);
        int n = s.length();
        
        vector<string> result;
        
        for(int i = 1; i<n; i++) {
            string a = s.substr(0, i);
            string b = s.substr(i);
            
            vector<string> left  = helper(a);
            vector<string> right = helper(b);
            
            for(const string& s1 : left) {
                for(const string& s2 : right) {
                    result.push_back(getPair(s1, s2));
                }
            }
        }
        
        return result;
        
    }
    
    vector<string> helper(string& s) {
        int n = s.length();
        vector<string> result;
        if(s[0] == '0' && s[n-1] == '0') {
            if(n == 1) //we can't process "00", "000" and so on...
                result.push_back("0");
            return result;
        }
        
        if(s[0] == '0') {
            //example : 012 or 0012
            //we can only do 0.12 or 0.012 and no other way
            result.push_back("0." + s.substr(1));
            return result;
        }
        
        if(s[n-1] == '0') {
            //example : 120: we have no option because 1.20 no allowed, 12.0 not allowed
            result.push_back(s);
            return result;
        }
        
        result.push_back(s);
        for(int i = 1; i<n; i++) {
            string temp = s.substr(0, i) + "." + s.substr(i);
            result.push_back(temp);
        }
        return result;
        
    }
};
