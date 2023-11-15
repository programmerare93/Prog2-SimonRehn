from math import inf
from dataclasses import dataclass


@dataclass
class Tile:
    char: str
    row: int
    column: int


def is_land_mass(tile: Tile) -> bool:
    return tile.char == '#' or tile.char == 'S'


def is_same_tile(tile_a: Tile, tile_b: Tile) -> bool:
    return tile_a.row == tile_b.row and tile_a.column == tile_b.column


def list_contains_tile(tile: Tile, tiles: [Tile]):
    for t in tiles:
        if t is None:
            continue
        if is_same_tile(tile, t):
            return True
    return False


def row_contains_stockholm(row: [str]) -> (bool, int):
    for i, c in enumerate(row):
        if c == 'S':
            return True, i

    return False, inf


def get_tile(row: int, column: int, tiles: [str]) -> Tile:
    try:
        return Tile(tiles[row][column], row, column)
    except IndexError:
        return None


def get_adjacent_tiles(row: int, column: int, tiles: [str]) -> [Tile, Tile, Tile, Tile]:
    north_tile = get_tile(row + 1, column, tiles)
    south_tile = get_tile(row - 1, column, tiles)
    if row - 1 < 0:
        south_tile = None
    west_tile = get_tile(row, column - 1, tiles)
    if column - 1 < 0:
        west_tile = None
    east_tile = get_tile(row, column + 1, tiles)

    return [north_tile, south_tile, west_tile, east_tile]


def count_landmass(stockholm_tile: Tile, tiles: [str]) -> int:
    land_count = 1 # Innehåller redan stockholm
    counted_tiles: [Tile] = [stockholm_tile]
    adjacent_tiles = get_adjacent_tiles(stockholm_tile.row,
                                        stockholm_tile.column,
                                        tiles)

    for tile in adjacent_tiles:
        if tile is None:
            continue
        if not is_land_mass(tile):
            continue
        if list_contains_tile(tile, counted_tiles):
            continue

        land_count += 1
        counted_tiles.append(tile)
        current_adjacent = get_adjacent_tiles(tile.row, tile.column, tiles)
        for t in current_adjacent:
            if t is None:
                continue
            if not list_contains_tile(t, adjacent_tiles):
                adjacent_tiles.append(t)

    return land_count


def main():
    rows = int(input())
    columns = int(input())
    changes_count = int(input())

    tiles = []
    stockholm = Tile('S', inf, inf)
    for row in range(rows):
        tiles.append(input())
        contains_stockholm, column = row_contains_stockholm(tiles[row])
        if contains_stockholm:
            stockholm.row = row
            stockholm.column = column

    print(count_landmass(stockholm, tiles))

    for _ in range(changes_count):
        row, column = tuple(input().split(" "))
        row = int(row)
        column = int(column)
        tiles[row - 1] = tiles[row - 1][: column - 1] + '#' +  tiles[row - 1][column:]
        print(count_landmass(stockholm, tiles))

if __name__ == "__main__":
    main()
