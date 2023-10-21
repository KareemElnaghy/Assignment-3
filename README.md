[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/2y4gXh2Q)
<h2 align="center">CSCE 2211 Fall 2023 Applied Data Structures</h2>
<h2 align="right">Prof. Amr Goneid</h2>

:warning: :warning: :warning: :warning: :warning: :warning: :warning:
```diff
- Assignment due date Tuesday, October 24, 2023.
- You have to commit and push your code to GitHub after accomplishing any part of the assignment.
```
:warning: :warning: :warning: :warning: :warning: :warning: :warning:

<table border="0">
 <tr>
    <td><b style="font-size:20px">Prerequisites for the assignment</b></td>
    <td><b style="font-size:20px">How it works (testing cases)</b></td>
 </tr>
 <tr>
    <td>
    1. Create <a href ="https://account.jetbrains.com/login" target="_blank">JetBrains Account</a> & Apply for students pack.<br>    
    2. Download <a href="https://www.jetbrains.com/clion/download/#section=mac" target="_blank">CLion for Windows & Mac</a> and sign-in with your account.<br>    
    3. Sign in in the GitHub Desktop app on the PC<br>  
    4. Clone this repo on the assignment<br>
    5. Write your name and ID in a comment at the beginning of each file, then push it<br>
    </td>
    <td>
    1. Open the repo folder as a project on CLion<br> 
    2. Start writing your code in the <strong>mycode.cpp</strong> file<br>
    3. After you write the required parts, go to <strong>test-mycode.cpp</strong> and run the file<br>
    4. The Cpp file will show you passed tests<br>
    </td>
 </tr>
</table>

## The problem: Building a Dictionary for Major Cities in the World  
One of the many applications of Binary Search Trees is building a dictionary structure in which a key is used to search for a given item and to provide relevant information if the key is found.

## Objective  
Implement a dictionary for the Major Cities in the world in the form of a Binary Search Tree (BST). The data for major population cities on Earth is provided in the Excel file Major City List

An entry for a city in the file gives the city name, its latitude, its longitude, and the country in which the city exists. The objective of the dictionary is to be able to retrieve the city information
given the city name as the key. Your dictionary should be a growing one, i.e., it should be able to add major cities in separate runs. 



## Required Implementation:
1. The BST ADT
A Full implementation of the BST class is found at: [Codes](http://www1.aucegypt.edu/faculty/cse/goneid/csce2211/codes.rar)  
The BST ADT can be implemented with the following member functions:  
• **Constructor**: Construct an empty tree  
• **Destructor**: Destroy tree  
• **insert**: Insert an element into the tree  
• **empty**: Return True if tree is empty  
• **search**: Search for a key  
• **retrieve**: Retrieve data for a given key  
• **traverse**: In-Order Traversal of the tree  
• **preorder**: Pre-order traversal of the tree  
• **levelorder**: level-order traversal of the tree  
• **remove**: Remove an element from the tree  
Design and implement a template class BST with a minimum of the above member functions. Use a template node class that consists of a key part and a data part. The node should also have a pointer to the left sub-tree and a pointer to the right sub-tree.
2. Implement a program to build, maintain and use a BST dictionary with City Name representing the key part while the data part includes the latitude, the longitude, and the country.
The dictionary should provide the following functions:  
• Generate the dictionary in memory.  
• Save the dictionary to disk as a text file.  
• Download a dictionary from disk into memory (as a BST)  
• Update a dictionary with added cities if needed.  
• Search the dictionary given the City Name and obtain the latitude, the longitude, and the country.  
• Produce a listing of all dictionary entries.  
• Find the distance between two cities in the dictionary (see below how to compute the distance between two cities given their latitudes and longitudes).

## Notes on Implementation:  
[Check PDF](/2211Asn3F23.pdf)



***
Update `README.md` todo list below:
- [ ] Run Test cases successfully
- [ ] Submit your code on GitHub

:white_check_mark: Use `git status` to list all new or modified files that haven't yet been committed.

<p align="center">
  <b>Created by</b><br>
  <b>Mohamed Ibrahim Hany</b>
</p>
