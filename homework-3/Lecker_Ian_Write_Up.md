# Ian Lecker CSCE350

1. I organized my code into a separate function for each task, including a wrapper and helper functions when necessary. For example, to make calling the insert function easier, I added a wrapper that only requires you to add one argument instead of having to specificy the root of the BST each time it is called. It also avoids the confusion that a recursive function might induce, such as accidentally displaying UI text multiple times. The wrapper also contains the UI text so that the logic may be easily separated from the function call. The logic is also made private to prevent the user from getting direct access to the function and allowing for error checking in the wrapper, to avoid critical errors. The display wrapper uses a helper function, in order traversal, to render the tree in ascending order, as the case with the test cases. The getSmallestValue and getLargestValue simply recursively iterate down the tree left or right respectively to find the intended value;

2. I had particular trouble with writing the delete logic and figuring out the the getLargestValue function. The latter was rather simple to fix as I realized I was not properly returning the recursive function leading to incorrect behavior. The former required me writing out the steps for deleting a node with children on a piece of scratch paper to ensure I was handling the case correctly. Upon this I was able to figure out the correct way to connect the "grand parent" and "child" node, while deleting the "parent" node

3. I have included a makefile for easy compilation. ```make all``` to compile and ```make run``` to execute.


