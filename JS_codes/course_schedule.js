/**
 * 
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

Prev
 */

/**
 * @param {number} courses
 * @param {number[]} visited
 */

const dfs = (graph, course, visited) => {
    if (visited[course] === 1)
        return false;
    if (visited[course] === 2)
        return true;

    // mark this current node as BEING visited
    visited[course] = 1; 

    // Then check if its neignbouring nodes (i.e descandant) are visited
    if (graph.has(course)) {
        for (const desd of graph.get(course)) {
            if (!dfs(graph, desd, visited))
                return false;
        }
    }
    // if all decendant was visted then this node is visited
    visited[course] = 2;
    return true;
}


/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */

const canFinish = (numCourse, prerequisites) => {
    const graph = new Map();
    const visited = new Array(numCourse).fill(0);

    for (const [course, prereq] of prerequisites) {
        if (!graph.has(prereq))
            graph.set(prereq, []);
        graph.get(prereq).push(course);
    }

    for (let k = 0; k < numCourse; k++) {
        if (!dfs(graph, k, visited))
            return false;
    }
    return true; 
}

const numCourses = 2;
const prerequisites = [[1,0]];
console.log(canFinish(numCourses, prerequisites)); // Output: false

const numCourses2 = 2;
const prerequisites2 = [[1, 0], [0, 1]];
console.log(canFinish(numCourses2, prerequisites2)); // Output: false

const numCourses3 = 4;
const prerequisites3 = [[1,0],[2,0],[3,1],[3,2]];
console.log(canFinish(numCourses3, prerequisites3));