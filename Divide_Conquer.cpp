//MAX ELEMENT
// #include <iostream>

// using namespace std;
// int f(int arr[],int l,int h)
// {
//     if(l==h)
//     {
//         return arr[l];
//     }
//     int mid=(l+h)/2;
//     return max(f(arr,l,mid),f(arr,mid+1,h));
// }
// int main()
// {
//     int arr[]={2,1,5,18,7,3,9,8};
//     int ans=f(arr,0,7);
//     cout<<ans;
    

//     return 0;
// }

//SUM
// #include <iostream>

// using namespace std;
// int f(int arr[],int l,int h)
// {
//     int s=0;
//     if(l==h)
//     {
//         return arr[l];
//     }
//     int mid=(l+h)/2;
//     return s+=f(arr,l,mid)+f(arr,mid+1,h);
// }
// int main()
// {
//     int arr[]={2,1,5,18,7,3,9,8};
//     int ans=f(arr,0,7);
//     cout<<ans;
    

//     return 0;
// }

//COUNT
// #include <iostream>

// using namespace std;
// int f(int arr[],int l,int h,int x)
// {
//     int s=0;
//     if(l==h)
//     {
//         if(arr[l]==x)
//         {
//             return 1;
//         }
//         else
//         {
//             return 0;
//         }
//     }
//     int mid=(l+h)/2;
//     return s+=f(arr,l,mid,x)+f(arr,mid+1,h,x);
// }
// int main()
// {
//     int arr[]={2,2,5,18,2,3,9,8};
    
//     int x;
//     cout<<"ENTER ELEMENT TO BE COUNTED : ";
//     cin>>x;
//     int ans=f(arr,0,7,x);
//     cout<<ans;
    

//     return 0;
// }

//FACTORIAL
#include <iostream>

using namespace std;
int f(int arr[],int l,int h)
{
    int fact=1;
    if(l==h)
    {
        return arr[l];
    }
    int mid=(l+h)/2;
    return fact=fact*(f(arr,l,mid)*f(arr,mid+1,h));
}
int main()
{
    
    int n;
    cout<<"ENTER NO : ";
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        arr[i-1]=i;
    }
    int ans=f(arr,0,n-1);
    cout<<ans;
    

    return 0;
}