>## <span style="color:red">[Naive Approach] Using Sorting - O(n * log(n)) Time and O(1) Space</span>

**The Idea is to first sort the array in ascending order, which ensures that the smallest element is at the front.**
**Then, the code searches for the first number that is greater than the minimum to identify the second smallest.**
**If all elements are equal and no distinct second minimum exists, it returns -1.**

```java
public static ArrayList<Integer> minAnd2ndMin(int arr){
//sort the array
Arrays.sort(arr);
    
//find the length of the array
int n = arr.length;

//initialize the minimum and second minimum
int mini = arr[0];
int secmini = Integer.MIN_VALUE;

//find the first number greater than mini, store in secmini, then break
for (int i = 0; i < n; i++) {
if (arr[i] != mini) {
secmini = arr[i];
break;
}

//if second minimum doesn't exist
if (secmini == Integer.MIN_VALUE) {
ArrayList<Integer> result = new ArrayList<>();
result.add(-1);
return result;
}

//return result as ArrayList
ArrayList<Integer> result = new ArrayList<>();
result.add(mini);
result.add(secmini);
return result;
}
}
```

>## <span style="color:red">[Better Approach] Using Two Pass - O(n) Time and O(1) Space</span>

**The main idea of this approach is to find the smallest and second smallest distinct elements in the array using two separate passes.**
**In the first loop, it identifies the minimum value (mini) by comparing each element.**
**In the second loop, it looks for the smallest element that is not equal to the minimum, which becomes the second minimum (secmini).**
**This ensures that both values are distinct.**

```java
public static ArrayList<Integer> minAnd2ndMin(int[] arr) {
    int n = arr.length;
    int mini = Integer.MAX_VALUE;
    int secmini = Integer.MAX_VALUE;

    // First loop to find the minimum element 
    // in the array
    for (int i = 0; i < n; i++) {
        mini = Math.min(mini, arr[i]);
    }

    // Second loop to find the second minimum element
    for (int i = 0; i < n; i++) {
        if (arr[i] != mini) {
            secmini = Math.min(secmini, arr[i]);
        }
    }

    // if second minimum was not updated, it means
    // all elements are equal
    if (secmini == Integer.MAX_VALUE) {
        ArrayList<Integer> result = new ArrayList<>();
        result.add(-1);
        return result;
    }

    ArrayList<Integer> result = new ArrayList<>();
    result.add(mini);
    result.add(secmini);
    return result;
}
```


>## <span style="color:red">[Expected Approach] Using Single Pass - O(n) Time and O(1) Space</span>

**The main idea of this approach is to find the smallest and second smallest distinct elements by scanning the array only once.**
**It uses two variables: first for the minimum value and second for the second minimum.**

**The values are updated based on the following conditions:**

**=> If the current number is less than first: Update second = first and first = current number.**

**=> Else if the current number is greater than first but less than second: Update second = current number.**

```java
public static ArrayList<Integer> minAnd2ndMin(int[] arr) {
    int n = arr.length;
    ArrayList<Integer> result = new ArrayList<>();

    // need at least two elements to have a second minimum
    if (n < 2) {
        result.add(-1);
        return result;
    }

    // initialize first and second minimums to "infinity"
    int first = Integer.MAX_VALUE;
    int second = Integer.MAX_VALUE;

    // single pass over the array
    for (int i = 0; i < n; i++) {

        // found new minimum: shift down the old minimum
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        }

        // arr[i] is not equal to first but smaller than current second
        else if (arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }

    // if second was never updated, all elements were equal
    if (second == Integer.MAX_VALUE) {
        result.add(-1);
        return result;
    }

    // Return the two minima
    result.add(first);
    result.add(second);
    return result;
}
```
