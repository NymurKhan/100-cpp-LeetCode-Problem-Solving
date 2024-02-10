class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<vector<string>> sentences;
        
        int curSize=0;
        vector<string> sentence;

        // Step 1: Form sentences.
        for(auto word: words)
        {
            curSize+= word.size()+1;
            if(curSize> maxWidth+1)
            {
                sentences.push_back(sentence);
                sentence.clear();
                sentence.push_back(word);
                curSize= word.size()+1;
                continue;
            }
            
            sentence.push_back(word);
        }
        
        sentences.push_back(sentence);
        
        for(int i=0; i<sentences.size(); i++)
        {
            int m= sentences[i].size();
            if(m==1) //Step 3: Case of 1 word sentence
            {
                // cout<<sentences[i][0]<<endl;
                int sz= sentences[i][0].size();
                for(int j=0; j< maxWidth- sz; j++)
                    sentences[i][0].push_back(' ');
                
                // cout<<sentences[i][0].size()<<endl;
                continue;
            }
            
            if(i==sentences.size()-1) // Case of last sentence
            {
                int sz=0;
                for(int j=0; j<sentences[i].size()-1; j++) //words
                {
                    sentences[i][j].push_back(' ');
                    sz+= sentences[i][j].size();
                }
                // cout<<sz<<endl;
                sz+= sentences[i][sentences[i].size()-1].size();
                // cout<<sz<<endl;
                
                for(int j=0; j< maxWidth- sz; j++)
                    sentences[i][sentences[i].size()-1].push_back(' ');
                
                continue;
            }
            
            // Step 2: Calculation of spaces per word
            int sz=0;
            for(int j=0; j<sentences[i].size(); j++)
                sz+= sentences[i][j].size();
            
            int sp= maxWidth - sz;
            int sppw=  sp/(m-1);
            int nsz=0;
            
            for(int j=0; j< sentences[i].size()-1; j++)
            {
                for(int k=0; k<sppw; k++)
                    sentences[i][j].push_back(' ');
                
                nsz+= sentences[i][j].size();
            }
            
            nsz+= sentences[i][sentences[i].size()-1].size();
            
            // Handle remainder
            for(int j=0, k=0; j<sentences[i].size()&&  k< maxWidth-nsz; k++,j++)
            {
                sentences[i][j].push_back(' ');
            }
            
        }
        
        // Form answer in required format
        vector<string> ans;
        
        for(auto s: sentences)
        {
            string sen;
            for(auto w: s)
                sen+= w;
            ans.push_back(sen);
        }
        
        return ans;
    }
};