# TODO: Kolla om s är garanterad


from dataclasses import dataclass

from math import inf


@dataclass

class Tile:
    char: str
    row_index: int
    column_index: int
    already_counted: bool


def is_land_mass(tile: Tile) -> bool:

    return tile.char == '#' or tile.char == 'S'


def row_contains_stockholm(row: [str]) -> (bool, int):

    for i, c in enumerate(row):

        if c == 'S':

            return True, i

    return False, inf


def get_tile(tile_i, tile_j, tiles: [str]) -> Tile:
    try:
        return Tile(tiles[tile_i][tile_j], tile_i, tile_j, False)
    except IndexError:
        return None


def get_adjacent_tiles(tile_i: int, tile_j: int, tiles: [str]) -> [Tile, Tile, Tile, Tile]:
    north_tile = get_tile(tile_i + 1, tile_j, tiles)
    south_tile = get_tile(tile_i - 1, tile_j, tiles)
    west_tile = get_tile(tile_i, tile_j - 1, tiles)
    east_tile = get_tile(tile_i, tile_j + 1, tiles)

    return [north_tile, south_tile, west_tile, east_tile]


def count_land_tiles(tiles: [Tile]) -> int:
    land_count = 0
    for tile in tiles:
        if is_land_mass(tile) and not tile.already_counted:
            land_count += 1
            tile.already_counted = True
            #count_land_tiles(get_adjacent_tiles(tile.row_index, tile.column_index, land_mass),
            #                 land_mass)

    return land_count


def tiles_contain_uncounted_land(tiles: [Tile]) -> bool:
    for tile in tiles:
        if is_land_mass(tile) and not tile.already_counted:
            return True
    return False


def land_mass_available(tiles: [Tile], land_mass: [str]) -> bool:
    for tile in tiles:
        if tiles_contain_uncounted_land(get_adjacent_tiles(tile.row_index, tile.column_index, land_mass)):
            return True
    return False

def tile_is_connected(tile_index: int, row: [str]) -> bool:
    try:
        if not is_land_mass(row[tile_index - 1]):
            return False
    except IndexError:
        pass

    try:
        if not is_land_mass(row[tile_index + 1]):
            return False
    except IndexError:
        pass

    return True

def count_landmass(land_mass: [str], stockholm_tile: Tile) -> int:
    land_count = 1 # Innehåller redan 'S'
    current_tile = stockholm_tile
    current_row = stockholm_tile.row_index

    while True:
        row = land_mass[current_row]
        for i, tile in enumerate(row):
            if tile == '#' and tile_is_connected(i, row):
                land_count += 1

    tiles = get_adjacent_tiles(current_tile.row_index,
                               current_tile.column_index,
                               land_mass)

    while True:
        land_count += count_land_tiles(tiles)
        if not land_mass_available(tiles, land_mass):
            break

        for tile in tiles:
            land_count += count_land_tiles(get_adjacent_tiles(tile.row_index, tile.column_index, land_mass))

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

    land_count = 0
    stockholm_found = False
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
