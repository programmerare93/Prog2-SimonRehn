from math import inf
from dataclasses import dataclass


@dataclass
class Tile:
    char: str
    row: int
    column: int

    def __str__(self) -> str:
        return f"{self.row}x{self.column}"

    def __eq__(self, other: object) -> bool:
        return self.row == other.row and self.column == other.column


def is_land_mass(tile: Tile) -> bool:
    return tile.char == '#' or tile.char == 'S'


def list_contains_tile(tile: Tile, tiles: [Tile]):
    for t in tiles:
        if t is None:
            continue
        if t == tile:
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


def count_landmass(stockholm_tile: Tile, tiles: [str]):
    land_count = 1 # Innehåller redan stockholm
    counted_tiles: dict(str, bool) = {
        str(stockholm_tile) : True
    }

    adjacent_tiles = get_adjacent_tiles(stockholm_tile.row,
                                        stockholm_tile.column,
                                        tiles)

    for tile in adjacent_tiles:
        if tile is None:
            continue
        if not is_land_mass(tile):
            continue
        if str(tile) in counted_tiles:
            continue

        land_count += 1
        counted_tiles[str(tile)] = True
        current_adjacent = get_adjacent_tiles(tile.row, tile.column, tiles)
        for t in current_adjacent:
            if t is None:
                continue
            if str(t) not in counted_tiles:
                adjacent_tiles.append(t)

    return (land_count, counted_tiles)


def main():
    rows = int(input())
    columns = int(input())
    changes_count = int(input())

    tiles = []
    stockholm = Tile('S', inf, inf)
    for row in range(rows):
        tiles.append(list(input()))
        if stockholm.row != inf:
            continue
        contains_stockholm, column = row_contains_stockholm(tiles[row])
        if contains_stockholm:
            stockholm.row = row
            stockholm.column = column

    land_count, counted_tiles = count_landmass(stockholm, tiles)
    print(land_count)

    for _ in range(changes_count):
        row, column = tuple(input().split(" "))
        row = int(row)
        column = int(column)
        tiles[row - 1][column - 1] = '#'

        new_tile = Tile('#', row - 1, column - 1)
        new_adjacent = get_adjacent_tiles(new_tile.row, new_tile.column, tiles)
        for t in new_adjacent:
            if t is None:
                continue
            if not is_land_mass(t):
                continue
            if str(t) in counted_tiles:
                land_count += 1
                counted_tiles[str(new_tile)] = True
                for t2 in new_adjacent:
                    if t2 is None:
                        continue
                    if is_land_mass(t2) and str(t2) not in counted_tiles:
                        land_count += 1
                        counted_tiles[str(t2)] = True
                        t2_adjacent = get_adjacent_tiles(t2.row, t2.column, tiles)
                        for a in t2_adjacent:
                            if a is None:
                                continue
                            if str(a) not in counted_tiles:
                                new_adjacent.append(a)
                break

        print(land_count)


if __name__ == "__main__":
    main()
