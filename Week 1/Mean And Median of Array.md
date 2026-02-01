**To find mean**
**find sum of all numbers then divide it by total number of elements**

```java
public static int mean(int arr) {
int sum = 0;
for (int num: arr) {
sum += num;
}
//Floor of the mean
return sum / arr.length;
}
```

**To find median**
**sort the array then find middle element**
**if total elements are even then there are two middle element then take average of them**
**if there is only one middle element then return it**

```java
public static int median(int arr) {
int n = arr.length;

//sorting function
Arrays.sort(arr);

int result = 0;

//if there are two middle element
if (n%2 == 0) {
result = (arr[n / 2] + arr[(n / 2) - 1]) / 2;
}
//if there are only one middle element
else {
result = arr[n / 2];
}

return result;
}
```