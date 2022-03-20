class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.size();
        int dirarr[n];
        for(int i=0;i<n;i++){
            if(directions[i]=='L'){
                dirarr[i]=2;
            }
            else if(directions[i]=='R'){
                dirarr[i]=1;
            }
            else if(directions[i]=='S'){
                dirarr[i]=0;
            }
        }
        
        int colcount=0;
        for(int i=0;i<n-1;i++){
            if(dirarr[i]==1 && dirarr[i+1]==2){
                colcount+=2;
                dirarr[i]=0;
                dirarr[i+1]=0;
            }
            else if(dirarr[i]==1 && dirarr[i+1]==0){
                colcount+=1;
                dirarr[i]=0;
                dirarr[i+1]=0;
            }
            if(dirarr[i]==0 && dirarr[i+1]==2){
                colcount+=1;
                dirarr[i]=0;
                dirarr[i+1]=0;
            }
            if(dirarr[i]==1 && dirarr[i+1]==1){
                int j=i+1;
                while(dirarr[j]==1 && j<n-1){
                    j++;
                } 
                
                if(dirarr[j]==1){
                    break;
                }
                else{
                    colcount+=(j-i);
                    if(dirarr[j]==2){
                        colcount++;
                    }
                    i=j-1;
                    dirarr[j]=0;
                }
            }
        }
        
        return colcount;
    }
};