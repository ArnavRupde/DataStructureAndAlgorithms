vector<string> solve(string s) {
    vector<string> ans;
    string t = "";
    int count = 0;
    for (auto &c : s){
        if(c=='('){
            t+=c;
            count++;
        } else{
            t+=c;
            count--;
            if(t.length() % 2 == 0 && count==0){
                ans.push_back(t);
                t="";
            }
        }
    }   
    return ans;