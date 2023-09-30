def max_area(height):
    """

    :param height:

    """
    max_area = 0
    l, r = 0, len(height) - 1

    while l < r:
        area = min(height[l], height[r]) * (r - l)
        max_area = max(area, max_area)
        if height[l] > height[r]:
            r -= 1
        else:
            l += 1

    return max_area
