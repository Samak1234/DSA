**[Naive Approach] Using Sorting - O(n * log(n)) Time and O(1) Space**

**The Idea is to is first sorted the array in ascending order, which ensures that the smallest element is at the front.
Then, the code searches for the first number that is greater than the minimum to identify the second smallest.
If all elements are equal and no distinct second minimum exists, it returns -1.**

public static ArrayList<Integer> minAnd2ndMin(int arr){
**sort the array**
Arrays.sort(arr);

**find the length of the array**
int n = arr.length;

**initialize the minimum and second minimum**
int mini = arr[0];
int secmini = Integer.MIN_VALUE;

**find the first number greater than mini, store in secmini, then break**
for (int i = 0; i < n; i++) {
if (arr[i] != mini) {
secmini = arr[i];
break;
}

**if second minimum doesn't exist**
if (secmini == Integer.MIN_VALUE) {
ArrayList<Integer> result = new ArrayList<>();
result.add(-1);
return result;
}

**return result as ArrayList**
ArrayList<Integer> result = new ArrayList<>();
result.add(mini);
result.add(secmini);
return result;
}