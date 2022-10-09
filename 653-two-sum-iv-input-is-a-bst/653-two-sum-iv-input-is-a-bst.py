# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder(self,root,arr):
        if not root:
            return
        self.inorder(root.left,arr)
        arr.append(root.val)
        self.inorder(root.right,arr)
        return arr
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        arr=[]
        
        result = self.inorder(root,arr)
        # print(result,k)
        for i in range(len(result)):
            for j in range(len(result)):
                if (result[i] + result[j] ==k) & (i!=j) :
                    # print(result[i] + result[j],i,j)
                    return True
        return False

        