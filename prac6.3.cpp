#include <iostream>
using namespace std;
int main() {
int n1, n2;
     cout << "Enter size of first array: ";
     cin >> n1;
     cout << "Enter size of second array: ";
     cin >> n2;
int* a = new int[n1];
int* b = new int[n2];
     cout << "Enter elements of first array (sorted):\n";
for (int i = 0; i < n1; i++)
    {
     cin >> a[i];
    }
     cout << "Enter elements of second array (sorted):\n";
for (int i = 0; i < n2; i++)
   {
     cin >> b[i];
   }
int* c = new int[n1 + n2];
int i = 0, j = 0, k = 0;
while (i < n1 && j < n2) {
if (a[i] < b[j]) {
c[k] = a[i];
i++;
}
else
    {
        c[k] = b[j];
        j++;
    }
    k++;
}
while (i < n1)
{
    c[k++] = a[i++];
}
while (j < n2)
 {
    c[k++] = b[j++];
}
cout << "Merged array:\n";
for (int x = 0; x < n1 + n2; x++)
    {
        cout << c[x] << " ";
    }
cout << endl;
delete[] a;
delete[] b;
delete[] c;
cout<<"\n24CE036_Bristi\n";
return 0;
}
