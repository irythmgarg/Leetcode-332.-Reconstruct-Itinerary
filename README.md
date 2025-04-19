# Leetcode-332.-Reconstruct-Itinerary
✈️ Reconstruct Itinerary
This repository contains an efficient solution to the classic graph problem: Reconstruct Itinerary. Given a list of airline tickets represented by pairs of departure and arrival airports, the goal is to reconstruct the itinerary in lexicographical order starting from "JFK" such that all tickets are used exactly once.

🧠 Problem Statement
You are given a list of airline tickets represented as pairs [from, to].

Reconstruct the itinerary such that:

You begin at "JFK".

You visit all destinations exactly once.

The itinerary has the smallest lexical order if multiple valid ones exist.

🔧 Key Concepts
Graph Construction using an adjacency list.

Min-Heap (Priority Queue) to maintain destinations in lexicographical order.

Depth-First Search (DFS) using Hierholzer's algorithm for Eulerian Path.

Reverse Traversal: Since destinations are added post DFS, we reverse the final result.

🚀 Approach
Build a graph from the ticket list, mapping each departure to a min-heap of destinations.

Perform DFS traversal from "JFK":

Recurse into the lexicographically smallest destination.

Once no more paths are left from a node, backtrack and add to the result.

Reverse the result to get the correct itinerary order.
