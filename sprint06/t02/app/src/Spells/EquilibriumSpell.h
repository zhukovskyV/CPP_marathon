#pragma once

#include "ISpell.h"

namespace Spells {
class EquilibriumSpell : public ISpell {
public:
    bool cast(Creatures::Creature& spellcaster, Creatures::Creature& target) override;
    SpellType getType() const override;
};
}
