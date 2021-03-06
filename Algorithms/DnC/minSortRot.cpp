/*
 *  to find the minimun element in sorted and rotated array:
 *  we split the array in two, the by which the array is splitted check that:
 *  if middle is greater than last element min is present on the right side
 *  if middle is less than the last element min is present on the left side
 *  if middle - 1 number is greater then middle then middle is min
 *  Corner Case:
 *      if middle is zero then array is not rotated
 *      if middle is size - 1 then next is 0     
 */
#include <iostream>
#include <vector>
using namespace std;
int mid(int first,int last){
    return (first + last) / 2;
}
int min(vector<int>Arr){
    int left = 0;
    int right = Arr.size() - 1;
    int middle = mid(left, right);
    bool isMin = false;
    while(!isMin){
        if(middle == 0){
            if(Arr[middle] < Arr[middle + 1])
                isMin = true;
            else
                left = middle + 1;
        }
        else{
            int prev = Arr[middle - 1];
            int pres = Arr[middle];
            int next;
            if(middle + 1 == Arr.size())
                next = Arr[0];
            else
                next = Arr[middle + 1];
            int last = Arr[Arr.size()-1];
            if(prev > pres && pres < next)
                isMin = true;
            else if(pres > last)
                left = middle + 1;
            else if(pres < last)
                right = middle - 1;
        }
        if(!isMin)
            middle = mid(left, right);
    }
    return Arr[middle];
}
int main(){
    int T;
    cin>>T;
    for(int j=1;j <= T;j++){
        int N;
        cin >> N;
        vector<int> Arr(N);
        for (int i = 0; i < N;i++)
            cin >> Arr[i];
        cout << min(Arr)<<endl;
    }
}
