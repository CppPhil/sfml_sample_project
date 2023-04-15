#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window.hpp>

int main()
{
  sf::RenderWindow window{
    sf::VideoMode{sf::Vector2u{800, 600}},
    "My window"
  };
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);

  // Run the program as long as the window is open.
  while (window.isOpen())
  {
    // Check all the window's events that were
    // triggered since the last iteration of
    // the loop.
    sf::Event event{};
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    sf::CircleShape shape{50.f};
    shape.setFillColor(sf::Color{150, 50, 250});

    // Set a 10-pixel wide orange outline
    shape.setOutlineThickness(10.f);
    shape.setOutlineColor(sf::Color{250, 150, 100});

    window.draw(shape);

    // End the current frame
    window.display();
  }
}
