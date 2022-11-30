//Q) Imagine you have a 20GB file with one string per line. Explain how
//you would sort the file.
//Ans.
//
//
//We will use the divide and conquer method to sort this large data. Whole file data is
//divided into small chunks i.e. one string, then they are merged using merge sort.
//Steps :
//1) Divide the memory into small n chunks until chunk contains single string i.e.
//each part is sorted as it contain single element
//2) Merge two divided parts in sorted order
//3) While merging compare elements of one part with elements of another part
//and store accordingly as their order
//4) Merge all parts to form single sorted file
//5) Hence, the file will be sorted
//6) Time Complexity : O(nlogn)