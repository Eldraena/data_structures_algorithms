int n;
cin >> n;

for (int i = 0; i < (1 << n); i++) 
{
   for(int j = 0; j < n; j++) 
   {
      cout << ((i >> j) & 1) << " "; 
   }
   cout << endl;
}
