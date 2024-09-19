### Time Complexity of Heap Sort

Heap Sort is an efficient, comparison-based sorting algorithm that uses a binary heap data structure (specifically, a **Max Heap**). It consists of two main phases: **building the heap** and **repeatedly extracting the maximum element**.

#### 1. **Building the Max Heap**
- Initially, the unsorted array is converted into a Max Heap.
- This is typically done using the **heapify** process, which has a time complexity of **O(log n)** for each element.
- Since there are `n` elements, the total time complexity for building the heap is **O(n)**. This may be counterintuitive, but this can be proven mathematically, considering that most elements in the heap are near the leaves and require less work to heapify.

#### 2. **Heapify After Extraction**
- After building the heap, the sorting process involves repeatedly extracting the maximum element (which is always at the root) and then heapifying the remaining heap.
- The **extraction** operation takes **O(log n)** time because the heap property must be restored after removing the root.
- This extraction step is repeated **n** times (once for each element), resulting in a total time complexity of **O(n log n)** for this phase.

### **Overall Time Complexity:**
- Building the heap: **O(n)**
- Extracting elements and heapifying: **O(n log n)**

Thus, the total time complexity of Heap Sort is:

\[
\boxed{O(n \log n)}
\]

### Additional Details:
- **Best Case**: **O(n log n)** – Heap Sort doesn't depend on the initial order of the data (unlike some algorithms like quicksort), so the best, average, and worst cases all have the same complexity.
- **Average Case**: **O(n log n)**
- **Worst Case**: **O(n log n)** – Even if the input array is reverse-sorted or already sorted, Heap Sort will still follow the same process.

### Space Complexity:
- The space complexity of Heap Sort is **O(1)** for the in-place version, as it requires only a constant amount of extra space beyond the input array.