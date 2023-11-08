# TODO: Kolla om s är garanterad

from dataclasses import dataclass
from math import inf

@dataclass
class Tile:
    type: str
    row_index: int
    column_index: int
    already_counted: bool

def is_land_mass(tile: Tile) -> bool:
    return tile.type == '#' or tile.type == 'S'

def row_contains_stockholm(row: [str]) -> (bool, int):
    for i, c in enumerate(row):
        if c == 'S':
            return True, i
    return False, inf

def get_adjacent_tiles(tile_i: int, tile_j: int, tiles: [str]) -> [Tile, Tile, Tile, Tile]:
    return [Tile(tiles[tile_i + 1][tile_j], tile_i + 1, tile_j, False),
            Tile(tiles[tile_i - 1][tile_j], tile_i - 1, tile_j, False),
            Tile(tiles[tile_i][tile_j - 1], tile_i, tile_j - 1, False),
            Tile(tiles[tile_i][tile_j + 1], tile_i, tile_j + 1, False)]

def safe_get_adjacent_tiles(tile_i: int, tile_j: int, tiles: [str]) -> [Tile, Tile, Tile, Tile]:
    try:
        tiles = get_adjacent_tiles(tile_i, tile_j, tiles)
        return tiles
    except IndexError:
        # TODO: Hantera
        pass

def count_land_tiles(tiles: [Tile], land_mass: [str]) -> int:
    land_count = 0
    for tile in tiles:
        if is_land_mass(tile) and not tile.already_counted:
            land_count += 1
            tile.already_counted = True
            count_land_tiles(safe_get_adjacent_tiles(tile.row_index, tile.column_index, land_mass), land_mass)

    return land_count

def count_landmass(land_mass: [str], stockholm_tile: Tile) -> int:
    land_count = 1 # Innehåller redan 'S'
    current_tile = stockholm_tile

    tiles = safe_get_adjacent_tiles(current_tile.row_index,
                                    current_tile.column_index,
                                    land_mass)

    land_count += count_land_tiles(tiles, land_mass)

    """
    for i, tile in enumerate(tiles):
        if is_landmass(tile):
            land_count += 1
        new_tiles = get_adjacent_tiles(tile.row_index, tile.column_index, land_mass)
    """
    return land_count



def main():
    rows = int(input())
    columns = int(input())
    changes_count = int(input())
    
    land_mass = []
    stockholm = Tile('S', inf, inf, True)
    for i in range(rows):
        land_mass.append(input())
        contains_stockholm, column_index = row_contains_stockholm(land_mass[i])
        if contains_stockholm:
            stockholm.row_index = i
            stockholm.column_index = column_index

    print(count_landmass(land_mass, stockholm))

    #for _ in range(changes_count):
    #    i, j = tuple(input().split(" "))

if __name__ == "__main__":
    main()
