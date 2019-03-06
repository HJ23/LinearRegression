#include<iostream>
#include<math.h>
#include<vector>
 #include<time.h>
using namespace std;

class linearregression{
public:vector<double> temp;
public:vector<double> y_real;
       vector<vector<double> > x_real;
       vector<double> y_temp;
       int nn;
public:linearregression(int n){
       nn=n;
       }

void calculate_ytemp(){
       y_temp.clear();
       for(int n=0;n<y_real.size();n++){
         double ss=0;
         for(int u=0;u<temp.size();u++){
             ss+=temp[u]*x_real[n][u];
       }
         y_temp.push_back(ss);
       }
}

    
double costfunction(){
         double total=0;
         for(int x=0;x<y_real.size();x++){
             total+=pow((y_temp[x]-y_real[x]),2);
         }
         total=total/y_real.size();
         return total/2;
}
void gradient_cost(){

         for(int y=0;y<nn;y++){
             double total=0;
             for(int x=0;x<y_temp.size();x++){
              total+=(y_temp[x]-y_real[x])*x_real[x][y];
         }
         total=(0.01*total)/y_temp.size();
        // cout<<total<<endl;
         temp[y]=temp[y]-total;

    }
       
}
void showtemp(){
  for(int x=0;x<temp.size();x++){
    cout<<temp[x]<<",";
  }
  cout<<endl;
}


};

int main(){
 /*
 x=[1,2,3]
   [5,6,8]
   [3,4,2]
   [0,5,7]

  function=2*theta0+4*theta1+8*theta3
  y=[34,98,38,76]
  

 */

    vector<vector<double> > x(4);
    x[0].push_back(1);
    x[0].push_back(2);
    x[0].push_back(3);
    x[1].push_back(5);
    x[1].push_back(6);
    x[1].push_back(8);
    x[2].push_back(3);x[2].push_back(4);x[2].push_back(2);
    x[3].push_back(0);x[3].push_back(5);x[3].push_back(7);
    vector<double> y;
    y.push_back(34);
    y.push_back(98);y.push_back(38);y.push_back(76);

vector<double> temp;
temp.push_back(1);
 temp.push_back(1);
 temp.push_back(1);
linearregression aa(3);
  aa.y_real=y;
  aa.x_real=x;
  aa.temp=temp;
  clock_t start=clock();
    do{
  aa.calculate_ytemp();
  aa.gradient_cost();
  //cout<<aa.costfunction()<<endl;
  }while(aa.costfunction()>pow(10,-8));
  aa.showtemp();
  cout<<endl;
  cout<<"execution time : "<<float(clock()-start)/CLOCKS_PER_SEC;
}
