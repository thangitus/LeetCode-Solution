from collections import defaultdict
from typing import List
import heapq


class Food:
    def __init__(self, food_rating, food_name):
        self.food_rating = food_rating
        self.food_name = food_name

    def __lt__(self, other):
        if self.food_rating == other.food_rating:
            return self.food_name < other.food_name
        return self.food_rating > other.food_rating


class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.food_rating_map = {}
        self.food_cuisine_map = {}
        self.cuisine_food_map = defaultdict(list)

        for i in range(len(foods)):
            self.food_rating_map[foods[i]] = ratings[i]
            self.food_cuisine_map[foods[i]] = cuisines[i]
            heapq.heappush(self.cuisine_food_map[cuisines[i]], Food(ratings[i], foods[i]))

    def changeRating(self, food: str, newRating: int) -> None:
        self.food_rating_map[food] = newRating
        cuisineName = self.food_cuisine_map[food]
        heapq.heappush(self.cuisine_food_map[cuisineName], Food(newRating, food))

    def highestRated(self, cuisine: str) -> str:
        highest_rated = self.cuisine_food_map[cuisine][0]

        while self.food_rating_map[highest_rated.food_name] != highest_rated.food_rating:
            heapq.heappop(self.cuisine_food_map[cuisine])
            highest_rated = self.cuisine_food_map[cuisine][0]

        return highest_rated.food_name
