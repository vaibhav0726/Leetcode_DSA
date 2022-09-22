class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        map<char,int> m1;
        map<char,int> m2;
        int i =0;
        while(i<s.size()){
            m1[s[i]]++;
            i++;
        }
        i=0;
        while(i<s.size()){
            m2[t[i]]++;
            i++;
        }
        auto it1 = m1.begin();
        auto it2 = m2.begin();

        while(it1!= m1.end() && it2!=m2.end()){
            if(it1 == m1.end() || it2 == m2.end()){
                return false;
            }
            if(it1->first != it2->first || it1->second != it2->second) return false;
            else cout<<"true";
            it1++;
            it2++;
        }
        if(it1!=m1.end()) return false;
        if(it2!=m2.end()) return false;

        cout<<endl;
        return true;
    }
};