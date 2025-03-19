import heapq
import copy

class PuzzleState:
    def __init__(self, board, g=0, parent=None, move=None):
        self.board = board
        self.g = g  # cost to reach this state
        self.parent = parent
        self.move = move
        self.h = self.calculate_heuristic()
        self.f = self.g + self.h
    
    def calculate_heuristic(self):
        # Misplaced tiles heuristic
        target = [1, 2, 3, 8, None, 4, 7, 6, 5]
        return sum(1 for i in range(9) if self.board[i] != None and self.board[i] != target[i])
    
    def __lt__(self, other):
        return self.f < other.f
    
    def __eq__(self, other):
        return self.board == other.board
    
    def __hash__(self):
        return hash(tuple(self.board))
    
    def get_blank_position(self):
        return self.board.index(None)
    
    def get_possible_moves(self):
        moves = []
        blank_pos = self.get_blank_position()
        
        # Define possible moves based on blank position
        # Up, Right, Down, Left
        directions = [
            (-3, "Up"),    # Move up
            (1, "Right"),  # Move right
            (3, "Down"),   # Move down
            (-1, "Left")   # Move left
        ]
        
        for direction, move_name in directions:
            new_pos = blank_pos + direction
            
            # Check if the move is valid
            if (
                (new_pos >= 0 and new_pos < 9) and
                (move_name != "Right" or blank_pos % 3 != 2) and
                (move_name != "Left" or blank_pos % 3 != 0)
            ):
                yield (new_pos, move_name)

def solve_puzzle(initial_state, goal_state):
    # Convert to flat array representation if needed
    if isinstance(initial_state, list) and len(initial_state) == 3:
        initial_flat = []
        for row in initial_state:
            initial_flat.extend(row)
        initial_state = initial_flat
        
    if isinstance(goal_state, list) and len(goal_state) == 3:
        goal_flat = []
        for row in goal_state:
            goal_flat.extend(row)
        goal_state = goal_flat
    
    start = PuzzleState(initial_state)
    
    # Priority queue for A* search
    open_set = []
    heapq.heappush(open_set, start)
    
    # To keep track of visited states
    closed_set = set()
    
    while open_set:
        current = heapq.heappop(open_set)
        
        # Check if we've reached the goal
        if current.board == goal_state:
            # Reconstruct the path
            path = []
            while current.parent:
                path.append(current.move)
                current = current.parent
            path.reverse()
            return path
        
        # Add to closed set
        state_tuple = tuple(current.board)
        if state_tuple in closed_set:
            continue
        closed_set.add(state_tuple)
        
        # Generate all possible moves
        for new_blank_pos, move_name in current.get_possible_moves():
            # Create a new board with the move applied
            new_board = current.board.copy()
            blank_pos = current.get_blank_position()
            
            # Swap the blank with the tile
            new_board[blank_pos], new_board[new_blank_pos] = new_board[new_blank_pos], new_board[blank_pos]
            
            # Create a new state
            new_state = PuzzleState(new_board, current.g + 1, current, move_name)
            
            # If this state is already explored, skip it
            if tuple(new_state.board) in closed_set:
                continue
            
            heapq.heappush(open_set, new_state)
    
    return None  # No solution found

def print_board(board):
    for i in range(0, 9, 3):
        row = board[i:i+3]
        print(" ".join(str(x) if x is not None else "_" for x in row))
    print()

def main():
    # From the first image, I'm using the initial and final states provided
    initial_state = [2, 8, 3, 1, 6, 4, 7, None, 5]
    goal_state = [1, 2, 3, 8, None, 4, 7, 6, 5]
    
    print("Initial State:")
    print_board(initial_state)
    
    print("Goal State:")
    print_board(goal_state)
    
    # Solve the puzzle
    solution = solve_puzzle(initial_state, goal_state)
    
    if solution:
        print(f"Solution found in {len(solution)} moves:")
        print(solution)
        
        # Show step-by-step solution
        current_state = initial_state.copy()
        print("\nStep-by-step solution:")
        print("Initial:")
        print_board(current_state)
        
        for step, move in enumerate(solution, 1):
            blank_pos = current_state.index(None)
            if move == "Up":
                new_pos = blank_pos - 3
            elif move == "Right":
                new_pos = blank_pos + 1
            elif move == "Down":
                new_pos = blank_pos + 3
            elif move == "Left":
                new_pos = blank_pos - 1
            
            current_state[blank_pos], current_state[new_pos] = current_state[new_pos], current_state[blank_pos]
            
            print(f"Step {step}: {move}")
            print_board(current_state)
    else:
        print("No solution found.")

if __name__ == "__main__":
    main()
