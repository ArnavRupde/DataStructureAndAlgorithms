class MedianFinder {
public:
     priority_queue<int>pq1;
    priority_queue<int, std::vector<int>, std::greater<int> >pq2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int val;
        if(pq1.size()==0)
            pq1.push(num);
        else if(pq1.top()>num)
            pq1.push(num);
        else
            pq2.push(num);
        if(pq1.size()>pq2.size()+1)
        {
            val=pq1.top();
            pq1.pop();
            pq2.push(val);
        }
        else if(pq1.size()+1<pq2.size())
        {
            val=pq2.top();
            pq2.pop();
            pq1.push(val);
        }
    }
    
    double findMedian() {
        if(pq1.size()>pq2.size())
            return pq1.top();
        else if(pq2.size()>pq1.size())
            return pq2.top();
        else
        {
            double val=pq1.top();
            val+=pq2.top();
            val=val/2;
            return val;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */