class MyCircularDeque {
    int[] arr;
    int ind = -1;
    public MyCircularDeque(int k) {
        arr = new int[k];
        Arrays.fill(arr,-1);
    }
    
    public boolean insertFront(int value) {
        if(ind+1 == arr.length) return false;
        for(int i = ind;i>=0;i--) {
            arr[i+1] = arr[i];
        }
        arr[0] = value;
        ind++;
        return true;
    }
    
    public boolean insertLast(int value) {
        if(ind+1 == arr.length) return false;
        ind++;
        arr[ind] = value;
        return true;
    }
    
    public boolean deleteFront() {
        if(arr[0] == -1) return false;
        for(int i=0;i<ind;i++) {
            arr[i] = arr[i+1];
        }
        arr[ind] = -1;
        ind--;
        return true;
    }
    
    public boolean deleteLast() {
        if(ind == -1) return false;
        arr[ind] = -1;
        ind--;
        return true;
    }
    
    public int getFront() {
        return arr[0];
    }
    
    public int getRear() {
        if(ind < 0) return -1;
        if(ind == arr.length) return arr[ind-1];
        return arr[ind];
    }
    
    public boolean isEmpty() {
        if(ind == -1) return true;
        return false;
    }
    
    public boolean isFull() {
        if(ind == arr.length-1) return true;
        return false;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */