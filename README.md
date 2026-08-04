A work-in-progress city building game prototype in UE5.3. It's a recreation for [The Game Dev Channel's City Building Playlist](https://www.youtube.com/playlist?list=PLFYGCCDpMHmHJwhIRY6qNumAts--W8bTy) but using C++ instead of Blueprints.

[![Watch the video](https://img.youtube.com/vi/RqDowQ9bURY/hqdefault.jpg)](https://www.youtube.com/embed/RqDowQ9bURY)

# Features
- **Camera controls** — move, orbit, pitch, zoom, and free-roam, all driven by the Enhanced Input system.
- **Mouse interaction** — click objects in-world and highlight them via a dedicated `Clickable` component that swaps materials on hover/click.
- **Grid system** — the world is divided into a grid of cells (`CBGridManager`/`CBGridCell`) that track occupancy and neighbouring cells, used to validate where roads and buildings can be placed.
- **Placement system** — a shared `Ploppable` component drives building/road placement previews, validates placement against the grid (including road-adjacency rules at junctions), and shows valid/invalid preview materials.
- **Roads and buildings** — placeable actors (`CBPlaceableBase`) specialized into roads (`CBRoadTile`) and buildings (`CBBuilding`), managed by `CBRoadManager`.
- **HUD** — UMG-based widget for selecting buildings and roads, displaying available money, and highlighting the active selection.
- **Day/night cycle** — a time manager advances time of day with switchable speed modes (normal, fast, fastest).
- **Currency system** — a starting money pool per game state, with affordability checks and a "placeable bought" event that updates the HUD.
- **Random citizen generation** — citizens are spawned with a randomized skeletal mesh, gender, name (from data tables), age, education level, health, and relationship status.
