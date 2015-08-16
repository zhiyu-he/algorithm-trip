import java.util.*;

/**
 * LRU: Least Recently Used, 最少使用，当Cache到达最大Size的时候，淘汰掉最少使用滴元素
 * impl: 利用
 * @author hezhiyu on 15/8/13.
 */
public class LRUCache {

    // 自行实现双向链表，这样实现删除操作会在O(1)，后面会详细说明这个
    private class Node {
        private int key;
        private int value;
        private Node prev;
        private Node next;

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
            this.prev = null;
            this.next = null;
        }
    }

    private Map<Integer, Node> hash;
    private Node head;
    private Node tail;
    private int capacity;

    // @param capacity, an integer
    public LRUCache(int capacity) {
        this.hash = new HashMap<>();
        this.capacity = capacity;
        this.head = new Node(-1, -1);
        this.tail = new Node(-1, -1);
        head.next = tail;
        tail.prev = head;
    }

    // @return an integer
    public int get(int key) {
        // write your code here
        Node res = hash.get(key);
        if (res == null) {
            return -1;
        }
        res.prev.next = res.next;
        res.next.prev = res.prev;
        addToHead(res);
        return res.value;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    public void set(int key, int value) {
        // write your code here
        // 这里有两种情况: 1. 元素已存在，进行替换  2. 元素不存在，进行add
        if (get(key) != -1) {
            Node updateElement = hash.get(key);
            updateElement.value = value;
            hash.put(key, updateElement);
            return;
        }

        // 进行新增操作
        Node newElement = new Node(key, value);
        if (hash.size() == this.capacity) {
            // 删除最后一个节点
            hash.remove(tail.prev.key);
            tail.prev = tail.prev.prev;
            tail.prev.next = tail;
        }
        addToHead(newElement);
        hash.put(key, newElement);
    }

    private void addToHead(Node current) {
        // 这是第一个初始化
        // 添加到表头
        current.next = head.next;
        current.prev = head;
        head.next.prev = current;
        head.next = current;
    }

    public static void main(String[] args) {

        LRUCache lruCache = new LRUCache(2);
        lruCache.set(2, 1);
        lruCache.set(1, 1);
        System.out.println(lruCache.get(2));
        lruCache.set(4, 1);
        System.out.println(lruCache.get(1));
        System.out.println(lruCache.get(2));


        System.out.println("=================\n");
        /*
        LRUCache lruCache = new LRUCache(3);

        lruCache.set(1, 1);
        lruCache.set(2, 2);
        lruCache.set(3, 3);
        lruCache.set(4, 4);

        System.out.println(lruCache.get(4));
        System.out.println(lruCache.get(3));
        System.out.println(lruCache.get(2));
        System.out.println(lruCache.get(1));

        lruCache.set(5, 5);
        System.out.println(lruCache.get(1));
        System.out.println(lruCache.get(2));
        System.out.println(lruCache.get(3));
        System.out.println(lruCache.get(4));
        System.out.println(lruCache.get(5));
        */
    }
}
