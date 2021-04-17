import java.util.Scanner;

public class Sol6{
	
	public static void main(String[] args){
		
		Scanner s = new Scanner(System.in);
		
		//System.out.println("Enter array size");
		//int n = s.nextInt();
		
		int arr[] = new int[5];
		
		System.out.println("Enter Elements");
	
		for(int i=0;i<arr.length;i++)
		{
			arr[i] = s.nextInt();
		}
		
		reverse(arr);
	}
	
	public static void reverse(int arr[]){
		
		for(int i=arr.length-1;i>=0;i--)
		{
			if(arr[i]!=0)
			{
				System.out.print(arr[i]+" ");
			}
		}
	}
}
