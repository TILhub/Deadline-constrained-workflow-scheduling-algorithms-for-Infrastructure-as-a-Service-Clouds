//
//  Author: Sahil Malik
//  Dated: 1 Jan 2019
#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;
int nodes,n_proc;
vector<double> price;
vector<vector<int> > weight,identity,adj;
fstream ifs;
void print_file()
void read(char* file_name);
void read_helper(int nodes,int n_proc,vector<vector<int> > &arr);
template <typename T> void print_vector(vector<vector<T> >& arr){
    for(int i=0;i<arr.size();i++){
        cout<<"\t";
        for(int j=0;j<arr[i].size();j++)    cout<<arr[i][j]<<"\t";
        cout<<endl;
    }
}
int main(int argc,char* argv[])
{
	if(argv[1]==NULL){
		cout<<"\n\tError! No Input File Supplied.\n\n";
		cout<<"\tProgram Will Now Exit\n\n";
		getchar();
		exit(0);
	}
    read(argv[1]);
    for(int i=0;i<n_proc;i++)
        cout<<price[i]<<"\t";
    print_file();
    return 0;
}

void read_helper(int nodes,int n_proc,vector<vector<int> > &arr){
    for(int i=0;i<nodes;i++){
        vector<int> temp;
        int t;
        for(int j=0;j<n_proc;j++)
        {
            ifs>>t;
            temp.push_back(t);
        }
        arr.push_back(temp);
        temp.clear();
    }    
}
void read(char* file_name)
{

	ifs.open(file_name,ios::in);
    if(!ifs){
        cout<<"\n\tIllegal File Name. Program will exit now!\n\n";
        exit(0);
    }
	ifs>>nodes;
	ifs>>n_proc;
    for(int i=0;i<n_proc;i++)
    {
        double temp;
        ifs>>temp;
        price.push_back(temp);
    }
    
    read_helper(nodes,n_proc,weight);
   // read_helper(n_proc,n_proc,identity);
    read_helper(nodes,nodes,adj);
	ifs.close();
    cout<<"\n\tFile Name Supplied: [ "<<file_name<<" ]"<<endl;
	cout<<"\n\tGraph Supplied Nodes: [ "<<nodes<<" ]\n\n\tWith Discrete Processors: [ "<<n_proc<<" ]\n\n";
    cout<<"\tFile read Successfully\n\n\n";
}

void print_file(){
    cout<<"\n\n\tWeight Matrix\n\n";
    print_vector(weight);
   //cout<<"\n\n\tIdentity Matrix\n\n";
   // print_vector(identity);
    cout<<"\n\n\tAdj Matrix\n\n";
    print_vector(adj);
}