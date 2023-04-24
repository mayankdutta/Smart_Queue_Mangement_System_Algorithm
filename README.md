# Smart_Queue_Mangement_System_Algorithm

- Algirthm powering SQMS.
- for statistical use. 
- [output analysis](https://docs.google.com/spreadsheets/d/1YEiyJlPEfdzCgCVG8fJXoGJxDbKNDlao4ccvkCLtJ_w/edit?usp=sharing).

## Assumptions

- Assuming each patient taking consult time in between `3m` to `10m`.
- Assuming clinical timing from `10AM` to `2PM`. 
- for most efficiency Slots are assumed to be of `1hr`.

### Sample output1 

```
initial order: 4 score: 20 count late : 2 response time: [0:0:0] time of arrival: [10:2:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 3m 11s  
initial order: 3 score: 20 count late : 2 response time: [0:0:0] time of arrival: [10:15:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 6m 27s  
initial order: 6 score: 20 count late : 2 response time: [0:0:0] time of arrival: [11:0:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 4m 39s  
initial order: 8 score: 20 count late : 2 response time: [0:0:0] time of arrival: [11:5:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 5m 13s  
initial order: 11 score: 20 count late : 2 response time: [0:0:0] time of arrival: [11:52:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 5m 11s  
initial order: 5 score: 20 count late : 2 response time: [0:0:0] time of arrival: [12:7:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 6m 58s  
initial order: 7 score: 20 count late : 2 response time: [0:1:58] time of arrival: [12:12:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 9m 25s  
initial order: 10 score: 20 count late : 2 response time: [0:0:0] time of arrival: [12:22:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 6m 47s  
initial order: 17 score: 20 count late : 2 response time: [0:6:47] time of arrival: [12:22:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 5m 15s  
initial order: 16 score: 20 count late : 2 response time: [0:4:15] time of arrival: [12:23:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 7m 50s  
initial order: 13 score: 20 count late : 2 response time: [0:0:0] time of arrival: [12:47:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 4m 58s  
initial order: 12 score: 20 count late : 2 response time: [0:0:0] time of arrival: [12:54:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 9m 32s  
initial order: 23 score: 20 count late : 2 response time: [0:0:0] time of arrival: [13:5:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 5m 19s  
initial order: 25 score: 20 count late : 2 response time: [0:0:0] time of arrival: [13:12:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 5m 45s  
initial order: 24 score: 20 count late : 2 response time: [0:2:45] time of arrival: [13:15:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 7m 53s  
initial order: 15 score: 20 count late : 2 response time: [0:0:53] time of arrival: [13:22:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 9m 22s  
initial order: 22 score: 20 count late : 2 response time: [0:8:22] time of arrival: [13:23:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 7m 7s  
initial order: 14 score: 20 count late : 2 response time: [0:3:7] time of arrival: [13:27:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 9m 51s  
initial order: 20 score: 20 count late : 2 response time: [0:7:51] time of arrival: [13:29:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 9m 27s  
initial order: 21 score: 20 count late : 2 response time: [0:9:27] time of arrival: [13:29:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 8m 56s  
initial order: 1 score: 20 count late : 2 response time: [0:0:0] time of arrival: [13:43:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 5m 36s  
initial order: 9 score: 20 count late : 2 response time: [0:5:36] time of arrival: [13:43:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 8m 16s  
initial order: 18 score: 20 count late : 2 response time: [0:0:0] time of arrival: [13:57:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 8m 13s  
initial order: 19 score: 20 count late : 2 response time: [0:7:13] time of arrival: [13:58:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 9m 6s  
initial order: 2 score: 20 count late : 2 response time: [0:8:6] time of arrival: [13:59:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 8m 24s  
```

##### Maximum response time: 8m 22s

### Sample output2

```
initial order: 3 score: 20 count late : 2 response time: [0:0:0] time of arrival: [10:10:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 5m 55s  
initial order: 6 score: 20 count late : 2 response time: [0:0:0] time of arrival: [10:35:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 3m 47s  
initial order: 7 score: 20 count late : 2 response time: [0:0:0] time of arrival: [11:19:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 7m 49s  
initial order: 8 score: 20 count late : 2 response time: [0:0:0] time of arrival: [11:31:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 9m 18s  
initial order: 12 score: 20 count late : 2 response time: [0:1:18] time of arrival: [11:39:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 5m 54s  
initial order: 11 score: 20 count late : 2 response time: [0:4:54] time of arrival: [11:40:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 6m 38s  
initial order: 4 score: 20 count late : 2 response time: [0:0:0] time of arrival: [11:51:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 9m 51s  
initial order: 13 score: 20 count late : 2 response time: [0:0:0] time of arrival: [12:7:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 7m 59s  
initial order: 17 score: 20 count late : 2 response time: [0:2:59] time of arrival: [12:12:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 7m 47s  
initial order: 2 score: 20 count late : 2 response time: [0:3:47] time of arrival: [12:16:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 8m 30s  
initial order: 1 score: 20 count late : 2 response time: [0:0:0] time of arrival: [12:28:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 9m 44s  
initial order: 14 score: 20 count late : 2 response time: [0:0:0] time of arrival: [12:49:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 6m 8s  
initial order: 15 score: 20 count late : 2 response time: [0:1:8] time of arrival: [12:54:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 9m 47s  
initial order: 9 score: 20 count late : 2 response time: [0:8:47] time of arrival: [12:55:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 9m 27s  
initial order: 18 score: 20 count late : 2 response time: [0:7:27] time of arrival: [12:57:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 8m 31s  
initial order: 24 score: 20 count late : 2 response time: [0:0:31] time of arrival: [13:5:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 9m 57s  
initial order: 5 score: 20 count late : 2 response time: [0:6:57] time of arrival: [13:8:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 7m 7s  
initial order: 19 score: 20 count late : 2 response time: [0:0:0] time of arrival: [13:26:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 6m 42s  
initial order: 21 score: 20 count late : 2 response time: [0:6:42] time of arrival: [13:26:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 3m 57s  
initial order: 22 score: 20 count late : 2 response time: [0:3:57] time of arrival: [13:26:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 3m 36s  
initial order: 25 score: 20 count late : 2 response time: [0:0:0] time of arrival: [13:30:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 4m 48s  
initial order: 20 score: 20 count late : 2 response time: [0:0:0] time of arrival: [13:42:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 3m 52s  
initial order: 10 score: 20 count late : 2 response time: [0:0:0] time of arrival: [13:46:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 8m 38s  
initial order: 16 score: 20 count late : 2 response time: [0:7:38] time of arrival: [13:47:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 9m 10s  
initial order: 23 score: 20 count late : 2 response time: [0:0:10] time of arrival: [13:56:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 5m 28s  
```

##### Maximum response time: 8m 47s


### Sample output3 

```
initial order: 4 score: 20 count late : 2 response time: [0:0:0] time of arrival: [10:14:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 7m 51s  
initial order: 6 score: 20 count late : 2 response time: [0:7:51] time of arrival: [10:14:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 4m 39s  
initial order: 3 score: 20 count late : 2 response time: [0:0:0] time of arrival: [10:46:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 7m 18s  
initial order: 10 score: 20 count late : 2 response time: [0:0:0] time of arrival: [11:39:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 3m 12s  
initial order: 2 score: 20 count late : 2 response time: [0:0:0] time of arrival: [11:52:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 9m 15s  
initial order: 11 score: 20 count late : 2 response time: [0:0:0] time of arrival: [12:4:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 3m 19s  
initial order: 16 score: 20 count late : 2 response time: [0:0:0] time of arrival: [12:10:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 8m 3s  
initial order: 5 score: 20 count late : 2 response time: [0:0:0] time of arrival: [12:19:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 6m 29s  
initial order: 9 score: 20 count late : 2 response time: [0:2:29] time of arrival: [12:23:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 3m 3s  
initial order: 7 score: 20 count late : 2 response time: [0:0:0] time of arrival: [12:36:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 8m 40s  
initial order: 12 score: 20 count late : 2 response time: [0:6:40] time of arrival: [12:38:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 9m 16s  
initial order: 1 score: 20 count late : 2 response time: [0:0:0] time of arrival: [12:55:0] expected time: [ [10:0:0] -> [11:0:0] ] treated: 1 consult time: 3m 25s  
initial order: 17 score: 20 count late : 2 response time: [0:3:25] time of arrival: [12:55:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 5m 52s  
initial order: 22 score: 20 count late : 2 response time: [0:0:0] time of arrival: [13:11:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 6m 57s  
initial order: 13 score: 20 count late : 2 response time: [0:5:57] time of arrival: [13:12:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 3m 10s  
initial order: 24 score: 20 count late : 2 response time: [0:0:0] time of arrival: [13:27:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 6m 11s  
initial order: 21 score: 20 count late : 2 response time: [0:5:11] time of arrival: [13:28:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 8m 33s  
initial order: 18 score: 20 count late : 2 response time: [0:4:33] time of arrival: [13:32:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 7m 34s  
initial order: 23 score: 20 count late : 2 response time: [0:5:34] time of arrival: [13:34:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 3m 41s  
initial order: 8 score: 20 count late : 2 response time: [0:1:41] time of arrival: [13:36:0] expected time: [ [11:0:0] -> [12:0:0] ] treated: 1 consult time: 4m 20s  
initial order: 14 score: 20 count late : 2 response time: [0:0:0] time of arrival: [13:47:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 9m 23s  
initial order: 25 score: 20 count late : 2 response time: [0:8:23] time of arrival: [13:48:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 5m 13s  
initial order: 19 score: 20 count late : 2 response time: [0:4:13] time of arrival: [13:49:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 6m 34s  
initial order: 15 score: 20 count late : 2 response time: [0:1:34] time of arrival: [13:54:0] expected time: [ [12:0:0] -> [13:0:0] ] treated: 1 consult time: 9m 10s  
initial order: 20 score: 20 count late : 2 response time: [0:4:10] time of arrival: [13:59:0] expected time: [ [13:0:0] -> [14:0:0] ] treated: 1 consult time: 7m 39s  
```

##### Maximum response time: 7m 51s