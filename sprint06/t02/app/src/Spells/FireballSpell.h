#pragma once

#include "ISpell.h"

namespace Spells {
class FireballSpell : public ISpell {
public:
    bool cast(Creatures::Creature& spellcaster, Creatures::Creature& target) override;
    SpellType getType() const override;
};
}