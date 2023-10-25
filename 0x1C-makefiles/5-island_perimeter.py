#!/usr/bin/python3
"""Defines a function for calculating island perimeter."""

def island_perimeter(grid):
    """
    Calculate the perimeter of an island in the grid.

    The grid uses 0 for water and 1 for land.

    Args:
        grid (list): List of lists with 0 for water and 1 for land.
    Returns:
        Perimeter of the island defined in the grid.
    """
    w = len(grid[0])
    h = len(grid)
    e = 0
    s = 0

    for i in range(h):
        for j in range(w):
            if grid[i][j] == 1:
                s += 1
                if (j > 0 and grid[i][j - 1] == 1):
                    e += 1
                if (i > 0 and grid[i - 1][j] == 1):
                    e += 1
    return s * 4 - e * 2
