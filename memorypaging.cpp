#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
    int mbt[50];
    int i,j,k,pa,bs,bfree,bfree_mode,ps,js,var=0,var2=0,jn,job;
    cout<<"\n\t\t paging\n";
    cout<<"\n\t enter physical address space: ";
    cin>>pa;
    cout<<"\n\t enter the block size: ";
    cin>>bs;
    bfree=pa/bs;
    cout<<"\n\t the number of blocks are: "<<bfree<<"\n";
    bfree_mode=bfree;
    for(i=0;i<bfree;i++){
        mbt[i]=0;
    }
    cout<<"how many jobs do you want to enter?\n";
    cin>>jn;
    for(j=0;j<=jn+2;j++){
        cout<<"enter "<<j+1<<"job size:\n";
        cin>>job;
        k=var;
        var=job/bs;
        if(job%bs!=0)
        var+=1;
        if(var<=bfree){
            var2+=var;
            for(k;k<var2;k++){
                mbt[k]=j+1;

            }
            bfree-=var;
            cout<<"mbt[0]=OS reserved\n";
            for(i=1;i<bfree_mode;i++){
                cout<<"mbt["<<i<<"]="<<mbt[i]<<"\n";

            }
        
            
        }
        else if(var>bfree){
         cout<<"\nThe memory is not enough for the "<<j+1<<"\n";
         break;
        }
    }
    return 0;
}