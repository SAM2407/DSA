#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, arr[100];
  cout << "Enter the number of element in array1 = " << endl;
  cin >> n;
  cout << "Enter the element of array1= " << endl;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int m, brr[100];
  cout << "Enter the number of element in array2 = " << endl;
  cin >> m;
  cout << "Enter the element of array2 = " << endl;
  for (int i = 0; i < m; i++) {
    cin >> brr[i];
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int element = arr[i];
    for (int j = 0; j < m; j++) {
      if (element == brr[j]) {
        brr[j] = -1;
        ans.push_back(element);
      }
    }
  }
  cout << "Intersection of array1 and array2 is = " << endl;
  for (auto value : ans) {
    cout << value << " ";
  }
  cout << endl;
}
