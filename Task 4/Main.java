import java.util.Arrays;
// This is the code for the task 4 in the OS portfolio
class NumList {
	int arr[];
	public NumList(int [] arr) {
		this.arr = arr;
	}
	void get_average() {
		float avg = 0;
		int n = arr.length;
		for (int i=0; i<n; i++) {
			avg += arr[i];
		}
		avg /= n;
		System.out.printf("The average value is %.2f \n", avg);
	}
	
	void get_min() {
		int min = arr[0];
		int n = arr.length;
		for (int i=0; i<n; i++) {
			if (min > arr[i]) {
				min = arr[i];
			}
		}
		System.out.println("The minimum value is " + min);
	}
	
	void get_max() {
		int max = arr[0];
		int n = arr.length;
		for (int i=0; i<n; i++) {
			if (max < arr[i]) {
				max = arr[i];
			}
		}
		System.out.println("The maximum value is " + max);
	}
	
	void get_median() {
		int [] newArr = arr.clone();
		int n = newArr.length;
		Arrays.sort(newArr);
		double median;
		if (n % 2 == 0)
		    median = ((double)newArr[n/2] + (double)newArr[n/2 - 1])/2;
		else
		    median = (double) newArr[n/2];
		
		if (median % 1 == 0)
			System.out.println("The median value is " + (int) median);
		else
			System.out.printf("The median value is  %.2f \n", median);
	}
	
	void get_dev() {
		int sum = 0; 
		float SD = (float) 0.0;
        int n = arr.length;

        for(int i = 0; i<n; i++) {
            sum += arr[i];
        }

        double avg = ((float) sum)/n;

        for(int i = 0; i<n; i++) {
            SD += Math.pow(arr[i] - avg, 2);
        }

        SD =  (float) Math.sqrt(SD/n);
        System.out.printf("The standard deviation value is %.2f \n", SD);
	}
}



class Task1 extends Thread{
	NumList list;
	public Task1(NumList list) {
		this.list = list;
	}
	public void run() {
		list.get_average();
	}
}


class Task2 extends Thread{
	NumList list;
	public Task2(NumList list) {
		this.list = list;
	}
	public void run() {
		list.get_min();
	}
}

class Task3 extends Thread{
	NumList list;
	public Task3(NumList list) {
		this.list = list;
	}
	public void run() {
		list.get_max();
	}
}

class Task4 extends Thread{
	NumList list;
	public Task4(NumList list) {
		this.list = list;
	}
	public void run() {
		list.get_median();
	}
}

class Task5 extends Thread{
	NumList list;
	public Task5(NumList list) {
		this.list = list;
	}
	public void run() {
		list.get_dev();
	}
}

public class Main {

	public static void main(String[] args) {
		int arr[] = {80, 72, 11, 25, 59, 82, 99};
		NumList list = new NumList(arr);
		Task1 t1 = new Task1(list);
		Task2 t2 = new Task2(list);
		Task3 t3 = new Task3(list);
		Task4 t4 = new Task4(list);
		Task5 t5 = new Task5(list);
		t1.start();
		t2.start();
		t3.start();
		t4.start();
		t5.start();
	}

}
