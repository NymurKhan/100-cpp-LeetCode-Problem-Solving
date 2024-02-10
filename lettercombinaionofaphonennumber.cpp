class Solution {
public:
 
    vector<string> letterCombinations(string digits) {
        // return {};
        // if(digits)
        vector<string> s;
        s.push_back("");
        string a="abc";
        s.push_back(a);

        a="def";
        s.push_back(a);
        a="ghi";
        s.push_back(a);
        a="jkl";
        s.push_back(a);
        a="mno";
        s.push_back(a);
        a="pqrs";
        s.push_back(a);
        a="tuv";
        s.push_back(a);
        a="wxyz";
        s.push_back(a);


        vector<string> ans;

        if(digits.size()==0){
            return ans;
        }

        else if(digits.size()==1){
            string aa="";
            for( auto it:s[digits[0]-'0'-1]){
                aa.push_back(it);
                ans.push_back(aa);
                aa.pop_back();
            }
        }
        else if(digits.size()==2){
            string aa="";
            for(auto i:s[digits[0]-'0'-1]){
                aa.push_back(i);
                for(auto it:s[digits[1]-'0'-1]){
                    aa.push_back(it);
                    ans.push_back(aa);
                    aa.pop_back();
                }
                aa.pop_back();
            }
        }
        else if(digits.size()==3){
            string aa="";
            for(auto i:s[digits[0]-'0'-1]){
                aa.push_back(i);
                for(auto j:s[digits[1]-'0'-1]){
                    aa.push_back(j);
                    for(auto k:s[digits[2]-'0'-1]){
                       aa.push_back(k);
                       ans.push_back(aa);
                       aa.pop_back();
                    }
                    aa.pop_back();
                }
                aa.pop_back();
            }
        }

        else{
              string aa="";
            for(auto i:s[digits[0]-'0'-1]){
                aa.push_back(i);
                for(auto j:s[digits[1]-'0'-1]){
                    aa.push_back(j);
                    for(auto k:s[digits[2]-'0'-1]){
                       aa.push_back(k);
                       for(auto x:s[digits[3]-'0'-1]){
                           aa.push_back(x);
                           ans.push_back(aa);
                           aa.pop_back();
                       }
                       
                       aa.pop_back();
                    }
                    aa.pop_back();
                }
                aa.pop_back();
            }
        }

        return ans;


    }
};