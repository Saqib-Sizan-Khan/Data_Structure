#include<bits/stdc++.h>
using namespace std;

int left(int i)
{
    return i*2;
}

int right(int i)
{
    return i*2+1;
}

int parent(int i)
{
    return i/2;
}

bool is_max_heap(int h[],int heap_size)
{
    int i,p;

    for(i=heap_size; i>1; i--)
    {
        p = parent(i);

        if(h[p] < h[i])
        {
            return false;
        }
    }

    return true;
}

bool max_heapify(int h[],int heap_size,int i)
{
    int l,r,largest;

    l = left(i);
    r = right(i);

    if(l <= heap_size && h[l] > h[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if(r <= heap_size && h[r] > h[largest])
    {
        largest = r;
    }

    if(largest != i)
    {
        swap(h[i],h[largest]);

        max_heapify(h,heap_size,largest);
        return true;
    }
    else
    {
        return false;
    }
}

void print_heap(int h[],int heap_size)
{
    int i;

    for(i=1; i<=heap_size; i++)
    {
        cout<<h[i]<<" ";
    }

    cout<<endl;
}

void build_max_heap(int h[],int heap_size)
{
    for(int i=heap_size/2; i>=1; i--)
    {
        max_heapify(h,heap_size,i);
    }
}

void heap_sort(int h[],int heap_size)
{
    if(is_max_heap(h,heap_size))
    {
        cout<<"Sorted: ";
        for(int i=heap_size; i>=1; i--)
        {
            swap(h[1],h[i]);
            cout<<h[i]<<" ";
            heap_size -= 1;
            max_heapify(h,heap_size,1);
        }
        cout<<"\n";
    }

    else cout<<"Data's not are in Max-heap\n";
}

int main()
{
    int Size = 9;
    int h[] = {0,12,7,1,3,10,17,19,2,5};

    cout<<"1.Check the Structure is a Max-Heap or not"<<endl;
    cout<<"2.Heaping in individual Index"<<endl;
    cout<<"3.Print Heap"<<endl;
    cout<<"4.Convert to Max-Heap"<<endl;
    cout<<"5.Heap Sort"<<endl;

    while(1)
    {
        int op;
        cin>>op;

        if(op==1)
        {
            if(is_max_heap(h,Size))
            {
                cout<<"Given data's are in Max-Heap\n";
            }
            else
            {
                cout<<"Given data's are not in Max-Heap\n";
            }
        }
        else if(op==2)
        {
            cout<<"Enter the Index for Re-Heaping: ";
            int val;
            cin>>val;

            if(max_heapify(h,Size,val))
                cout<<"Re-Heaped\n";
            else
                cout<<"No Data Re-Heaped\n";
        }
        else if(op==3)
        {
            print_heap(h,Size);
        }
        else if(op==4)
        {
            build_max_heap(h,Size);
            cout<<"Converted\n";
        }
        else if(op==5)
        {
            heap_sort(h,Size);
        }
        else
        {
            break;
        }
    }
    return 0;
}
