//Desktop\padhai ka saman\IR\prog ass\2

#include <bits/stdc++.h>
using namespace std;
#define n 26		//26 letters in alphabet

void edit_dist(int cm[][n], string s1, string s2){
	int l1=s1.length();
	int l2=s2.length();
	int DP[l1+1][l2+1]={0};
	// initilize the array for indices 0
    for (int i = 0; i <= l1; i++){
        DP[i][0] = i;
    } 
    for (int j = 0; j <= l2; j++){
    	DP[0][j] = j;
    } 
    //computing the dp matrix   
	for(int i=1;i<l1+1;i++){
		for(int j=1;j<l2+1;j++){
			if (s1[i - 1] == s2[j - 1]){
				DP[i][j] = min(DP[i - 1][j - 1],  
                                   min(DP[i - 1][j]+1, 
                                   DP[i][j - 1]+1));
			}
			else{
				DP[i][j] = min(DP[i - 1][j - 1]+cm[s1[i - 1]-'a'][s2[j - 1]-'a'],  
                                   min(DP[i - 1][j]+1, 
                                   DP[i][j - 1]+1));
			}
		}
	}
	// cout<<"-----------------------------------"<<endl;
	// for(int i=0;i<l1+1;i++){
	// 	for(int j=0;j<l2+1;j++){
	// 		cout<<DP[i][j]<<"\t";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<"------------------------------------"<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"The cost matrix is-"<<endl;
	cout<<"    ";
	for(int i=0; i<=l2; i++)
	{
		cout<<s2[i]<<" ";
	}
	cout<<endl;
	for(int i=0; i<=l1; i++)
	{
		if(i>0)
		{
			cout<<s1[i-1]<<" ";
		}
		else
		{
			cout<<"  ";
		}
		for(int j=0; j<=l2; j++)
		{
			cout<< DP[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"------------------------------------"<<endl;
	cout<<"The Cost of conversion or the edit distance between "<<s1<<" and "<<s2<< " is: "<<DP[l1][l2]<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"The steps (from end to begining / in reverse order) are -"/*<<"\t"<<"the cost at this point is-"*/<<endl;
	//backtracing solution
	int i=l1,j=l2;
	//check till end
	 while (i and j) 
    { 
    	/*// if characters are same 
	    if (s1[i - 1] == s2[j - 1]) 
	    { 
	        cout<<"Same letters "<<s1[i - 1]<<endl;
	        i--; 
	        j--;
	    }
	    // Replace 
        else*/ if (DP[i][j] == DP[i - 1][j - 1] + cm[s1[i - 1]-'a'][s2[j - 1]-'a'])
        {
        	if (s1[i - 1] == s2[j - 1]){
        		cout<<"Same letters "<<s1[i - 1]<<endl;
        	}
        	else{
        		cout << "Change " << s1[i - 1]<< " to " << s2[j - 1] /*<<"\t\t\t"<<DP[i][j]*/<< endl;	
        	}
            i--; 
	        j--;
        }
        // Delete the character 
        else if (DP[i][j] == DP[i - 1][j] + 1) 
        { 
            cout << "Delete " << s1[i - 1] /*<<"\t\t\t"<<DP[i][j]*/<< endl; 
            i--; 
        } 
  		// Add the character 
        else if (DP[i][j] == DP[i][j - 1] + 1) 
        { 
            cout << "Insert " << s2[j - 1] /*<<"\t\t\t"<<DP[i][j]*/<< endl; 
            j--; 
        } 
    } 
    if(i){
    	//this means that now we have to delete other remaining letters
    	while(i){
    		cout << "Delete " << s1[i - 1] << endl; 
            i--;
    	}
    
    }
    else if(j){
    	//this means we have to insert remaining letters
    	while(j){
    		cout << "Insert " << s2[j - 1]<< endl; 
            j--;
    	}
    }

}

int main(){
	int conf_mat[n][n];
	ifstream is("conf_mat.txt");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			is >> conf_mat[i][j];
		}
	}
	is.close();
	// cout<<"-----------------------------------------"<<endl;
	// cout<<"conf matrix is-"<<endl;
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<< conf_mat[i][j]<<"\t";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<"----------------------------------------"<<endl;
	string incorrect,correct;
	cout<<"Give the incorrect word: ";
	cin>>incorrect;
	transform(incorrect.begin(), incorrect.end(), incorrect.begin(), ::tolower); 
	cout<<"Give the correct word: ";
	cin>>correct;
	transform(correct.begin(), correct.end(), correct.begin(), ::tolower);
	edit_dist(conf_mat,incorrect,correct);
	cout<<"----------------------------------------"<<endl;
	cout<<"Thankyou!! :)"<<endl;
	return 0;
}