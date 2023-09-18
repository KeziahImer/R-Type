# R-type

R-type is a project that aims to reimagine the classic game "R-type" in C++ using a custom game engine and implementing networked multiplayer functionality.

## Development

### Getting Started
To download, build, and run the code, follow these steps:

1. **Clone the Repository**: 
   ```sh
   git clone https://github.com/organisation/r-type.git
   cd r-type
   ```

2. **Build the Code**:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Run the Client**:
   ```sh
   ./r-type_client
   ```

4. **Run the Server**:
   ```sh
   ./ r-type_server
   ```

## Contribution

We welcome contributions to improve R-type. To contribute, please follow these guidelines:

- **Gitmoji Usage**: Use [gitmoji](https://gitmoji.dev/) in your commit messages to convey the purpose of your changes.

- **Rebasing**: Before submitting a pull request, ensure your changes are based on the latest `dev` branch. Use `git rebase` to incorporate the latest changes into your branch.

- **Pull Request Description**: Provide a clear and concise description of the task or feature you are addressing in your pull request.

## How to Doc

R-type's documentation is generated using MkDocs. To contribute to the documentation, follow these steps:

1. **Install MkDocs**:
   ```
   pip install mkdocs
   ```

2. **Add Content**:
   Add or edit documentation content in the `docs` directory.

3. **Generate Documentation**:
   ```
   mkdocs build
   ```

4. **Preview Documentation**:
   To preview the documentation locally, use the following command:
   ```
   mkdocs serve
   ```
   This will start a local development server, and you can view the documentation by navigating to `http://localhost:8000` in your web browser.

5. **Commit and Push**:
   Commit your changes to the documentation and push them to the repository.

Remember to keep the documentation up-to-date as you make changes to the project.

Feel free to reach out if you have any questions or need further assistance. Happy coding! 🚀