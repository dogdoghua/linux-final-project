# linux-final-project

## Description
在kernel中define 3個wait queue : project2_queue_1、project2_queue_2、project2_queue_3
新增兩個system call
- int enter_wait_queue(int x)
    - process can use it to sleep in project2_queue_x, where x is equal to 1 or 2 or 3
- int clean_wait_queue(int x)
    - process can use it to wake up all sleeping processes in project2_queue_x where x is equal to 1 or 2 or 3.
    

## Method
wait_queue 提供4個 function 可以使用，兩個是用來將 process 加到 wait_queue 的:
  - sleep_on( struct wait_queue **wq );
  - interruptible_sleep_on( struct wait_queue **wq );
另外兩個則是將process從wait_queue上叫醒的。
  - wake_up( struct wait_queue **wq );
  - wake_up_interruptible( struct wait_queue **wq );
  
如果是用 interruptible_sleep_on() 來將 process 放到 wait_queue 時，如果有人送一個 signal 給這個 process，那它就會自動從 wait_queue 中醒來。
但是如果你是用 sleep_on() 把 process 放到 wq 中的話，那不管你送任何的 signal 給它，它還是不會理你的。除非你是使用 wake_up() 將它叫醒。
sleep 有兩組。wake_up 也有兩組。wake_up_interruptible() 會將 wq 中使用 interruptible_sleep_on() 的 process 叫醒。
至於 wake_up() 則是會將 wq 中所有的 process 叫醒。包括使用 interruptible_sleep_on() 的 process。所以根據project要求，我們應該用wake_up()
