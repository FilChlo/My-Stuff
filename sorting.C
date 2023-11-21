/*Program is used to check
 *how long each sorting algorithm
 *takes to sort a vector
*/
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void BubbleSort(vector<int>& l);
void SelectionSort(vector<int>& l2);
void InsertionSort(vector<int>& l3);
void Pass(vector<int>& l, long len);
void Swap(int& x, int& y);

void BubbleSort(vector<int>& l)
{
        double start=time(0);
        long len=l.size();
        for (long i=0; i<len; i++) {
                Pass(l, len);
        }
        double end=time(0);
        double finale=end-start;
        cout << fixed << setprecision(2) << finale << endl;
}

void SelectionSort(vector<int>& l2)
{
        double start=time(0);
        long last=l2.size()-1;
        long current=0;
        int small=current;
        while (current < last) {
                small=current;
                for (long i=current+1; i<=last; i++) {
                        if (l2[i]<l2[small]) {
                                small=i;
                        }
                }
                Swap(l2[current], l2[small]);
                current++;
        }
        double end=time(0);
        double finale=end-start;
        cout << fixed << setprecision(2) << finale << endl;
}

void InsertionSort(vector<int>& l3)
{
        double start=time(0);
        long size=l3.size();
        for (long i=0; i<size; i++) {
                long num=l3[i];
                long j=i-1;
                while (j>=0 && num<=l3[j]) {
                        l3[j+1]=l3[j];
                        j=j-1;
                }
                l3[j+1]=num;
        }
        double end=time(0);
        double finale=end-start;
        cout << fixed << setprecision(2) << finale << endl;
}

void Pass(vector<int>& l, long len)
{
        for (long i=0; i<len-1; i++) {
                if (l[i]>l[i+1]) {
                        Swap(l[i], l[i+1]);
                }
        }
}

void Swap(int& x, int& y)
{
        int tmp=x;
        x=y;
        y=tmp;
}

int main()
{
        double amount=100000.0;
        srand(time(0));
        vector<int> list(amount, rand()%100+1);
        vector<int> list2(amount);
        vector<int> list3(amount);
        for (int i=0; i<list.size(); i++) {
                list2.push_back(list[i]);
                list3.push_back(list[i]);
        }
        BubbleSort(list);
        SelectionSort(list2);
        InsertionSort(list3);

        return 0;
}
    
